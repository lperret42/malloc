#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/mman.h>

# define PAGE_SIZE			getpagesize()
# define NB_ALLOC_MIN		128
# define TINY_LENGTH		2 * PAGE_SIZE
# define TINY_ALLOC_MAX		TINY_LENGTH / NB_ALLOC_MIN
# define SMALL_LENGTH		8 * TINY_LENGTH
# define SMALL_ALLOC_MAX	SMALL_LENGTH / NB_ALLOC_MIN

void	free(void *ptr);
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);
void	show_alloc_mem();

#endif
