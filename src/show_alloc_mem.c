/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:10:09 by lperret           #+#    #+#             */
/*   Updated: 2018/04/09 11:28:53 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t		show_and_get_alloc_mem_in_one_not_large_page(void *p,
										t_page_type page_type, size_t num_page)
{
	size_t		num_block;
	size_t		nb_block_user;
	void		*begin;
	size_t		total;
	size_t		b_s;

	b_s = page_type == TINY ? TINY_BLOCK_SIZE : SMALL_BLOCK_SIZE;
	if (page_type == TINY && num_page == 0)
		ft_printf("TINY : %#lX\n", (unsigned long)get_page_mem_begin(p, b_s));
	else if (num_page == 0)
		ft_printf("SMALL : %#lX\n", (unsigned long)get_page_mem_begin(p, b_s));
	nb_block_user = get_nb_block_user(b_s);
	total = 0;
	num_block = -1;
	while (++num_block < nb_block_user)
	{
		if (get_is_free_block(p + sizeof(void*), num_block) == 0)
		{
			begin = get_page_mem_begin(p, b_s) + b_s * num_block;
			total += b_s;
			show_alloc_mem_between_two_addr(begin, begin + b_s);
		}
	}
	return (total);
}

size_t		show_and_get_alloc_mem_in_one_large_page(void *page,
															size_t num_page)
{
	size_t		size;
	void		*begin;

	size = *((unsigned long *)(page + sizeof(void*)));
	size -= sizeof(void*) + sizeof(unsigned long);
	if (num_page == 0)
		ft_printf("LARGE : %#lX\n",
				(unsigned long)get_page_mem_begin(page, SMALL_BLOCK_SIZE + 1));
	begin = page + sizeof(void*) + sizeof(unsigned long);
	show_alloc_mem_between_two_addr(begin, begin + size);
	return (size);
}

size_t		show_and_get_alloc_mem_in_one_page(void *page,
									t_page_type page_type, size_t num_page)
{
	if (page_type == LARGE)
		return (show_and_get_alloc_mem_in_one_large_page(page, num_page));
	else
		return (show_and_get_alloc_mem_in_one_not_large_page(page,
														page_type, num_page));
}

size_t		show_alloc_mem_by_type(void *page, t_page_type page_type)
{
	size_t		total;
	size_t		n;
	size_t		nb_page;
	void		**pages;

	nb_page = get_nb_page(page);
	if (!page || !(pages = (void**)mmap(NULL, sizeof(void*) * nb_page,
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (0);
	n = 0;
	while (page)
	{
		pages[n++] = page;
		page = read_void_star_in_memory(page);
	}
	sort_pages(pages, nb_page);
	total = 0;
	n = 0;
	while (n < nb_page)
	{
		total += show_and_get_alloc_mem_in_one_page(pages[n], page_type, n);
		n++;
	}
	munmap(pages, sizeof(void*) * nb_page);
	return (total);
}

void		show_alloc_mem(void)
{
	void		**first_pages;
	size_t		total;

	total = 0;
	first_pages = get_first_pages();
	total += show_alloc_mem_by_type(first_pages[TINY], TINY);
	total += show_alloc_mem_by_type(first_pages[SMALL], SMALL);
	total += show_alloc_mem_by_type(first_pages[LARGE], LARGE);
	if (total > 0)
		ft_printf("Total : %lu octets\n", total);
}
