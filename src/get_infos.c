/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:55:53 by lperret           #+#    #+#             */
/*   Updated: 2018/04/02 13:25:54 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t				get_mem_len(size_t size)
{
	t_page_type		page_type;

	page_type = get_page_type(size);
	if (page_type == TINY)
		return TINY_LEN;
	else if (page_type == SMALL)
		return SMALL_LEN;
	else
		return size;
}

void				*read_void_star_in_memory(void *mem)
{
	int				nb_char;
	unsigned char	*tmp_uc;
	unsigned long	tmp_lu;

	nb_char = sizeof(void*);
	tmp_uc = (unsigned char*)mem;
	tmp_lu = 0;
	while (--nb_char >= 0)
		tmp_lu += *(tmp_uc + nb_char);
	return ((void*)tmp_lu);
}

size_t		get_page_block_size(size_t size)
{
	t_page_type		page_type;

	page_type = get_page_type(size);
	if (page_type == TINY)
		return TINY_BLOCK_SIZE;
	else if (page_type == SMALL)
		return SMALL_BLOCK_SIZE;
	else
		return size;
}

t_page_type		get_page_type(size_t size)
{
	if (size <= TINY_BLOCK_SIZE)
		return TINY;
	else if (size > TINY_BLOCK_SIZE && size <= SMALL_BLOCK_SIZE)
		return SMALL;
	else
		return LARGE;
}

size_t		get_is_free_space_size(int nb_block)
{
	return (nb_block / 8) + (nb_block % 8 > 0 ? 1 : 0);
}

size_t		get_malloc_size(size_t size)
{
	size_t			nb_block;
	size_t			is_free_space_size;
	
	nb_block = get_nb_block(size);
	is_free_space_size = get_is_free_space_size(nb_block);
	if (size <= SMALL)
		return (sizeof(void*) + is_free_space_size);
	else
		return (sizeof(void*) + sizeof(unsigned long));
}

void	*get_page_mem_begin(void *page, size_t size)
{
	size_t			nb_block;
	size_t			is_free_space_size;
	
	nb_block = get_nb_block(size);
	is_free_space_size = get_is_free_space_size(nb_block);

	return (void*)((char*)page + sizeof(void*) + is_free_space_size);
}
