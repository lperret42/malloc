/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:38:55 by lperret           #+#    #+#             */
/*   Updated: 2018/04/06 15:11:32 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
//# include <stdio.h>
# include <string.h>
//# include <stdlib.h>
# include <sys/mman.h>
# include "../libft/includes/libft.h"

# define NB_BLOCK_TINY_TOTAL			256
# define NB_BLOCK_SMALL_TOTAL			128

# define PAGESIZE				getpagesize()

# define TINY_LEN				2 * PAGESIZE
# define TINY_BLOCK_SIZE		(size_t)(TINY_LEN / NB_BLOCK_TINY_TOTAL)

# define SMALL_LEN				32 * PAGESIZE
# define SMALL_BLOCK_SIZE		(size_t)(SMALL_LEN / NB_BLOCK_SMALL_TOTAL)

typedef enum		e_page_type
{
	TINY,
	SMALL,
	LARGE,
	NB_PAGE_TYPE,
}					t_page_type;

void			free(void *ptr);
void			*malloc(size_t size);
void			*realloc(void *ptr, size_t size);
void			show_alloc_mem(void);

void			*read_void_star_in_memory(void *mem);

void			**get_first_pages(void);
void			*get_first_page(size_t size);

size_t			get_malloc_mem_size(size_t size);
size_t			get_user_mem_size(size_t size);
size_t			get_total_mem_size(size_t size);

size_t			get_page_block_size(size_t size);
t_page_type		get_page_type(size_t size);
size_t			get_page_size_from_type(void *page, t_page_type page_type);
size_t			get_nb_block_user(size_t size);
void			*get_page_mem_begin(void *page, size_t size);
void			*get_alloc_page(size_t size);
void			del_page(void *page, t_page_type page_type);
int				add_page(size_t size);

size_t			get_is_free_space_size(int nb_block);
int				get_is_free_block(void *begin, int num_block);
void			set_is_free_block(void *begin, int num_block, int is_free);
int				search_num_free_block(void *begin, size_t nb_block);
void			*get_free_block(size_t size);

long			get_num_block_of_ptr_in_page(void *page, t_page_type page_type,
				void *ptr);

void			show_alloc_mem_between_two_addr(void *begin, void *end);
size_t			get_nb_page(void *page);
void			sort_pages(void **pages, size_t nb_page);

#endif
