/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem_tools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:12:02 by lperret           #+#    #+#             */
/*   Updated: 2018/04/06 15:13:37 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		show_alloc_mem_between_two_addr(void *begin, void *end)
{
	size_t		nb_octets;

	nb_octets = end - begin;
	ft_printf(
			"%#lX - %#lX : %lu octets\n",
			(unsigned long)begin,
			(unsigned long)end,
			nb_octets);
}

size_t		get_nb_page(void *page)
{
	size_t		nb_page;

	nb_page = 0;
	while (page)
	{
		nb_page++;
		page = read_void_star_in_memory(page);
	}
	return (nb_page);
}

void		sort_pages(void **pages, size_t nb_page)
{
	size_t		n;
	void		*tmp;

	if (nb_page < 2)
		return ;
	n = 0;
	while (n < nb_page - 1)
	{
		if (pages[n + 1] < pages[n])
		{
			tmp = pages[n];
			pages[n] = pages[n + 1];
			pages[n + 1] = tmp;
			n = 0;
		}
		else
			n++;
	}
}
