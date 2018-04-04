/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:53:45 by lperret           #+#    #+#             */
/*   Updated: 2018/04/04 16:36:19 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t	get_page_type_from_ptr(void *ptr)
{
	t_page_type		page_type;
	void			*page;

	page_type = 0;
	while (page_type < NB_PAGE_TYPE)
	{
		page = get_first_pages()[page_type];
		while (page != NULL)
		{
			if (page_type != LARGE)
			{
				if (get_num_block_of_ptr_in_page(page, page_type, ptr) != -1)
					return (page_type);
			}
			else
			{
				if (page + sizeof(void*) + sizeof(unsigned long) == ptr)
					return (page_type);
			}
			page = read_void_star_in_memory(page);
		}
		page_type++;
	}
	return (-1);
}

void	*realloc_not_large(void *ptr, size_t size, t_page_type old_page_type)
{
	size_t		old_block_size;
	size_t		new_block_size;
	void		*ret;

	if (old_page_type == TINY)
		old_block_size = TINY_BLOCK_SIZE;
	else
		old_block_size = SMALL_BLOCK_SIZE;
	new_block_size = get_page_block_size(size);
	if (new_block_size <= old_block_size)
		return (ptr);
	else
	{
		ret = malloc(size);
		if (!ret)
			return (NULL);
		memcpy(ret, ptr, size);
		free(ptr);
		return (ret);
	}
}

void	*realloc_large(void *ptr, size_t size)
{
	size_t			old_size;
	size_t			new_size;
	size_t			overflow;
	void			*ret;

	old_size = *((unsigned long *)((char*)ptr - sizeof(unsigned long)));
	overflow = PAGESIZE - old_size % PAGESIZE;
	new_size = get_total_mem_size(size);
	if (new_size <= old_size + overflow)
		return (ptr);
	else
	{
		ret = malloc(size);
		if (!ret)
			return (NULL);
		memcpy(ret, ptr, size);
		free(ptr);
		return (ret);
	}
}

void	*realloc(void *ptr, size_t size)
{
	long	page_type;

	if (!ptr)
		return (malloc(size));
	page_type = get_page_type_from_ptr(ptr);
	if (page_type == -1)
		return (NULL);
	if (page_type == LARGE)
		return (realloc_large(ptr, size));
	return (realloc_not_large(ptr, size, page_type));
}
