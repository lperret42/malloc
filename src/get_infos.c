/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:55:53 by lperret           #+#    #+#             */
/*   Updated: 2018/04/04 14:08:51 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t			get_page_block_size(size_t size)
{
	if (size <= TINY_BLOCK_SIZE)
		return (TINY_BLOCK_SIZE);
	else if (size <= SMALL_BLOCK_SIZE)
		return (SMALL_BLOCK_SIZE);
	else
		return (size);
}

void			*read_void_star_in_memory(void *mem)
{
	int				nb_char;
	unsigned char	*tmp_uc;
	unsigned long	tmp_lu;

	nb_char = sizeof(void*);
	tmp_uc = (unsigned char*)mem;
	tmp_lu = 0;
	while (--nb_char >= 0)
		tmp_lu += *(tmp_uc + nb_char) * (nb_char + 1);
	printf("tmp_lu: %lu\n", tmp_lu);
	return ((void*)tmp_lu);
}

t_page_type		get_page_type(size_t size)
{
	if (size <= TINY_BLOCK_SIZE)
		return (TINY);
	else if (size > TINY_BLOCK_SIZE && size <= SMALL_BLOCK_SIZE)
		return (SMALL);
	else
		return (LARGE);
}

size_t			get_is_free_space_size(int nb_block_total)
{
	return (nb_block_total / 8) + (nb_block_total % 8 > 0 ? 1 : 0);
}

void			*get_page_mem_begin(void *page, size_t size)
{
	return (void*)((char*)page + get_malloc_mem_size(size));
}
