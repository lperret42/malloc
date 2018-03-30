/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:00:33 by lperret           #+#    #+#             */
/*   Updated: 2018/03/30 16:26:17 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t		get_nb_block(size_t size)
{
	if (size <= TINY_BLOCK_SIZE)
		return (TINY_LEN - sizeof(void*)) / TINY_BLOCK_SIZE;
	else if (size <= SMALL_BLOCK_SIZE)
		return (SMALL_LEN - sizeof(void*)) / SMALL_BLOCK_SIZE;
	else
		return 1;
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

int				search_num_free_block(void *begin_is_free_space, size_t nb_block)
{
	size_t		num_block;

	num_block = 0;
	while (num_block < nb_block)
	{
		if (get_is_free_block(begin_is_free_space, num_block) == 1)
			return num_block;
		num_block++;
	}

	return -1;
}

void			*get_free_block(size_t size)
{
	size_t			block_size;
	t_page_type		page_type;
	size_t			nb_block;
	void			*page;
	int				num_free_block;

	block_size = get_page_block_size(size);
	page_type = get_page_type(size);
	nb_block = get_nb_block(size);
	page = get_first_page(size);
	num_free_block = -1;
	while (page != NULL)
	{
		num_free_block = search_num_free_block((void*)((char*)page + sizeof(void*)), nb_block);
		if (num_free_block != -1)
			break;
		page = (void*)(*(unsigned long*)page);   // need to add a safer way to get next page
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
	return (void*)((char*)get_page_mem_begin(page, size) + num_free_block * block_size);
}
