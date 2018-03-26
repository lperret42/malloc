/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:00:33 by lperret           #+#    #+#             */
/*   Updated: 2018/03/26 15:05:43 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

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

	return is_free;
}

void		set_is_free_block(void *begin, int num_block, int is_free)
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

size_t			get_nb_block(size_t size)
{
	t_page_type		page_type;

	page_type = get_page_type(size);
	if (page_type == LARGE)
		return 1;
	else
		return NB_BLOCK;
}

int				search_num_free_block(void *begin_is_free_space, size_t nb_block)
{
	size_t		num_block;

	num_block = 0;
	while (num_block < nb_block)
	{
		if (get_is_free_block(begin_is_free_space, num_block))
			return num_block;
		num_block++;
	}

	return -1;
}

void			*get_free_block(size_t size)
{
	size_t			nb_block;
	size_t			block_size;
	int				num_free_block;
	void			*page;
	t_page_type		page_type;

	nb_block = get_nb_block(size);
	block_size = get_page_block_size(size);
	page_type = get_page_type(size);
	page = get_first_page(size);
	num_free_block = -1;
	while (page != NULL)
	{
		num_free_block = search_num_free_block((void*)((char*)page + sizeof(void*)), size);
		if (num_free_block != -1)
			break;
		page = (void*)(*(unsigned long*)page);
	}
	if (num_free_block == -1)
	{
		add_page(size);
		page = get_first_page(size);
		if (page == NULL)    // mmap failed
			return NULL;
		num_free_block = 0;
	}
	set_is_free_block((void*)((char*)page + sizeof(void*)), num_free_block, 0);
	return (void*)((char*)get_page_mem_begin(page, page_type) + num_free_block * block_size);
}
