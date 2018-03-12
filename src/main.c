#include "malloc.h"

int		main(void)
{
	int		i;
	int		a;
	int		page_size;
	char	*str;

	page_size = 5000;
	str = (char*)malloc(page_size + 1);
	if (str == 0)
		return -1;
	i = 0;
	while (i < page_size)
	{
		str[i] = '*';
		i++;
	}
	str[i] = '\0';
	//printf("%s", str);
	printf("PAGE_SIZE: %d\n", PAGE_SIZE);
	printf("NB_ALLOC_MIN: %d\n", NB_ALLOC_MIN);
	printf("TINY_LENGTH: %d\n", TINY_LENGTH);
	printf("TINY_ALLOC_MAX: %d\n", TINY_ALLOC_MAX);
	printf("SMALL_LENGTH: %d\n", SMALL_LENGTH);
	printf("SMALL_ALLOC_MAX: %d\n", SMALL_ALLOC_MAX);

	return (0);
}
