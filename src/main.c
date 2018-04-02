#include "malloc.h"

int		main(void)
{
	size_t		i;
	long int	n;
	int			nb_times;
	char		*str;

	str = malloc(0);
	str = malloc(42);
	str = malloc(100);
	str = malloc(40000);
	nb_times = 10000;
	n = 9000;
	while (nb_times > 0)
	{
		str = (char*)malloc(n + 1);
		printf("nb_times: %d, str: %p\n", nb_times, str);
		if (str == NULL)
			return -1;
		i = 0;
		while (i < n)
			str[i++] = '*';
		str[i] = '\0';
		nb_times--;
	}
	
	printf("%s\n", str);
	printf("NB_BLOCK_TOTAL: %d\n", NB_BLOCK_TOTAL);
	printf("TINY_LEN: %d\n", TINY_LEN);
	printf("TINY_BLOCK_SIZE: %lu\n", TINY_BLOCK_SIZE);
	printf("SMALL_LEN: %d\n", SMALL_LEN);
	printf("SMALL_BLOCK_SIZE: %lu\n", SMALL_BLOCK_SIZE);
	printf("%s\n", str);
	return (0);
}
