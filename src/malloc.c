#include "malloc.h"

void	*malloc(size_t size)
{
	void			*ret;

	ret = get_free_block(size);
	return ret;
}
