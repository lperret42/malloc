#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <sys/mman.h>
# include "libft_printf.h"

void	free(void *ptr);
void	*ft_malloc(size_t size);
void	*realloc(void *ptr, size_t size);

#endif
