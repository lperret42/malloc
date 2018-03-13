#include "malloc.h"

int		main(void)
{
	int		i;
	int		n;
	char	*str;

	n = 42;
	str = (char*)malloc(n + 1);
	if (str == 0)
		return -1;
	i = 0;
	while (i < n)
		str[i++] = '*';
	str[i] = '\0';
	printf("%s\n", str);
	
	printf("PAGE_SIZE: %d\n", PAGE_SIZE);
	printf("NB_ALLOC_MIN: %d\n", NB_ALLOC_MIN);
	printf("TINY_LENGTH: %d\n", TINY_LENGTH);
	printf("TINY_ALLOC_MAX: %d\n", TINY_ALLOC_MAX);
	printf("SMALL_LENGTH: %d\n", SMALL_LENGTH);
	printf("SMALL_ALLOC_MAX: %d\n", SMALL_ALLOC_MAX);

	printf("%s\n", str);
	return (0);
}
