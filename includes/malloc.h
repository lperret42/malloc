/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:38:55 by lperret           #+#    #+#             */
/*   Updated: 2018/03/30 16:54:19 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/mman.h>

# define NB_BLOCK			128

# define TINY_LEN			2 * getpagesize()
# define TINY_BLOCK_SIZE	(size_t)(TINY_LEN / NB_BLOCK)

# define SMALL_LEN			8 * TINY_LEN
# define SMALL_BLOCK_SIZE	(size_t)(SMALL_LEN / NB_BLOCK)

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
void			show_alloc_mem();

void			*read_void_star_in_memory(void *mem);

void			**get_first_pages(void);
void			*get_first_page(size_t size);

size_t			get_mem_len(size_t size);
size_t			get_page_block_size(size_t size);
t_page_type		get_page_type(size_t size);
size_t			get_nb_block(size_t size);
void			*get_page_mem_begin(void *page, size_t size);
void			*get_alloc_page(size_t size);
void			add_page(size_t size);

size_t			get_is_free_space_size(int nb_block);
int				get_is_free_block(void *begin, int num_block);
void			set_is_free_block(void *begin, int num_block, int is_free);
int				search_num_free_block(void *begin, size_t nb_block);
void			*get_free_block(size_t size);

#endif
