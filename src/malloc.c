#include "malloc.h"

void	*ft_malloc(size_t size)
{
	void	*ret;

	ret = mmap(NULL, size, PROT_READ | PROT_WRITE,
					MAP_ANON | MAP_PRIVATE, -1, 0);

	return ret;
}
