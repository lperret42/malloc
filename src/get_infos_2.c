/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:08:09 by lperret           #+#    #+#             */
/*   Updated: 2018/04/06 13:31:05 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t			get_user_mem_size(size_t size)
{
	size_t			malloc_size;

	ft_putstr("size: ");
	ft_putnbr(size);
	ft_putstr("\n");
	malloc_size = get_malloc_mem_size(size);
	if (size <= TINY_BLOCK_SIZE)
		return (TINY_LEN - malloc_size);
	else if (size <= SMALL_BLOCK_SIZE)
		return (SMALL_LEN - malloc_size);
	else
		return (size);
}

size_t			get_malloc_mem_size(size_t size)
{
	size_t			nb_block_user;
	size_t			is_free_space_size;

	nb_block_user = get_nb_block_user(size);
	is_free_space_size = get_is_free_space_size(nb_block_user);
	if (size <= SMALL_BLOCK_SIZE)
		return (sizeof(void*) + is_free_space_size);
	else
		return (sizeof(void*) + sizeof(unsigned long));
}

size_t			get_total_mem_size(size_t size)
{
	if (size <= TINY_BLOCK_SIZE)
		return (TINY_LEN);
	else if (size <= SMALL_BLOCK_SIZE)
		return (SMALL_LEN);
	else
		return (size + sizeof(void*) + sizeof(unsigned long));
}

size_t			get_page_size_from_type(void *page, t_page_type page_type)
{
	size_t		page_size;

	if (page_type == TINY)
		page_size = TINY_LEN;
	else if (page_type == SMALL)
		page_size = SMALL_LEN;
	else
		page_size = *((unsigned long *)((char*)page + sizeof(void*)));
	return (page_size);
}
