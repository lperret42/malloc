/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:35:53 by lperret           #+#    #+#             */
/*   Updated: 2018/04/02 12:59:48 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			**get_first_pages(void)
{
	static void	*first_pages[3] = {NULL, NULL, NULL};

	return (first_pages);
}

void			*get_first_page(size_t size)
{
	t_page_type		page_type;

	page_type = get_page_type(size);
	return (get_first_pages()[page_type]);
}

void			*get_alloc_page(size_t size)
{
	size_t		nb_block_user;
	size_t		is_free_space_size;
	size_t		alloc_size;
	void		*begin_is_free_space;
	void		*alloc_page;

	nb_block_user = get_nb_block_user(size);
	is_free_space_size = get_is_free_space_size(nb_block_user);
	alloc_size = get_total_mem_size(size);
	printf("alloc_size: %lu\n", alloc_size);
	alloc_page = (void*)mmap(NULL, alloc_size, PROT_READ | PROT_WRITE,
						MAP_ANON | MAP_PRIVATE, -1, 0);
	begin_is_free_space = (void*)((char*)alloc_page + sizeof(void*));
	memset(begin_is_free_space, 255, is_free_space_size);
	if (size > SMALL_BLOCK_SIZE)
	{
		*((unsigned long *)((char*)alloc_page + sizeof(void*))) = size;
	}
	return (alloc_page);
}

void		del_page(void *page, t_page_type page_type)
{
	void	**first_pages;
	void	*prev;
	void	*next_page;
	size_t	page_size;

	first_pages = get_first_pages();
	next_page = read_void_star_in_memory(page);
	if (page == first_pages[page_type])
		first_pages[page_type] = next_page;
	else
	{
		prev = first_pages[page_type];
		next_page = read_void_star_in_memory(prev);
		while (next_page != page)
		{
			prev = next_page;
			next_page = read_void_star_in_memory(prev);
		}
		next_page = read_void_star_in_memory(page);
		memcpy(prev, next_page, sizeof(void*));
	}
	if (page_type == TINY)
		page_size = TINY_LEN;
	else if (page_type == SMALL)
		page_size = SMALL_LEN;
	else
		page_size = *((unsigned long *)((char*)page + sizeof(void*)));
	munmap(page, page_size);
	printf("del page\n");
}

void			add_page(size_t size)
{
	t_page_type		page_type;
	void			**first_pages;
	void			*tmp;
	void			*new_page;

	page_type = get_page_type(size);
	first_pages = get_first_pages();
	tmp = first_pages[page_type];
	new_page = get_alloc_page(size);
	if (tmp == NULL)
		memset(new_page, 0, sizeof(void*));
	else
		memcpy(new_page, tmp, sizeof(void*));
	first_pages[page_type] = new_page;
	printf("page++\n");
}
