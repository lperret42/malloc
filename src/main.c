#include "malloc.h"

int		main(void)
{
	size_t		i;
	long int	n;
	int			nb_times;
	char		*str;

	nb_times = 100000;
	n = 15;
	while (nb_times > 0)
	{
		str = (char*)malloc(n + 1);
		if (str == NULL)
			return -1;
		i = 0;
		while (i < n)
			str[i++] = '*';
		str[i] = '\0';
		nb_times--;
	}
	
	printf("%s\n", str);
	printf("NB_BLOCK: %d\n", NB_BLOCK);
	printf("TINY_LEN: %d\n", TINY_LEN);
	printf("TINY_BLOCK_SIZE: %lu\n", TINY_BLOCK_SIZE);
	printf("SMALL_LEN: %d\n", SMALL_LEN);
	printf("SMALL_BLOCK_SIZE: %lu\n", SMALL_BLOCK_SIZE);
	printf("%s\n", str);
	return (0);
}
