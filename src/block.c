/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:00:33 by lperret           #+#    #+#             */
/*   Updated: 2018/04/06 15:22:19 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t	get_nb_block_user(size_t size)
{
	t_page_type		page_type;
	size_t			nb_block_user;

	page_type = get_page_type(size);
	if (page_type == LARGE)
		return (0);
	else if (page_type == TINY)
		nb_block_user = (sizeof(void *) * TINY_LEN -
				(sizeof(void*) * (sizeof(void*) + 1))) /
									(sizeof(void*) * TINY_BLOCK_SIZE + 1);
	else
		nb_block_user = (sizeof(void *) * SMALL_LEN -
				(sizeof(void*) * (sizeof(void*) + 1))) /
									(sizeof(void*) * SMALL_BLOCK_SIZE + 1);
	return (nb_block_user);
}

int		get_is_free_block(void *begin, int num_block)
{
	int		octet_num;
	int		bit_num;
	char	c;
	int		is_free;

	octet_num = num_block / 8;
	bit_num = num_block % 8;
	c = *((char*)begin + octet_num);
	is_free = (c >> bit_num) & 1;
	return (is_free);
}

void	set_is_free_block(void *begin, int num_block, int is_free)
{
	int		octet_num;
	int		bit_num;
	char	*c;

	octet_num = num_block / 8;
	bit_num = num_block % 8;
	c = (char*)begin + octet_num;
	if (is_free == 1)
		*c = *c | (1 << bit_num);
	else
		*c = *c & (~(1 << bit_num));
}

int		search_num_free_block(void *begin_is_free_space, size_t nb_block_user)
{
	size_t		num_block;

	num_block = 0;
	while (num_block < nb_block_user)
	{
		if (get_is_free_block(begin_is_free_space, num_block) == 1)
		{
			return (num_block);
		}
		num_block++;
	}
	return (-1);
}

void	*get_free_block(size_t size)
{
	void			*p;
	long			num_free;

	p = get_first_page(size);
	num_free = -1;
	while (p != NULL)
	{
		num_free = search_num_free_block(p + sizeof(void*),
													get_nb_block_user(size));
		if (num_free != -1)
			break ;
		p = read_void_star_in_memory(p);
	}
	if (num_free == -1)
	{
		if (add_page(size) != 1)
			return (NULL);
		if ((p = get_first_page(size)) == NULL)
			return (NULL);
		if (size > SMALL_BLOCK_SIZE)
			return (get_page_mem_begin(p, size));
		num_free = 0;
	}
	set_is_free_block(p + sizeof(void*), num_free, 0);
	return (get_page_mem_begin(p, size) + num_free * get_page_block_size(size));
}
