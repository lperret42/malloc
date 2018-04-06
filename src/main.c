#include "malloc.h"

int		main(void)
{
	long int	i;
	long int	n;
	int			nb_times;
	char		*str;

	str = malloc(10);
	str = malloc(500);
	str = malloc(40000);
	str = malloc(40000);
	nb_times = 50000;
	n = 30;
	str = NULL;
	while (nb_times > 0)
	{
		str = (char*)malloc(n + 1);
		str = (char*)realloc(str, n + 1);
		if (str == NULL)
			return -1;
		i = 0;
		while (i < n)
			str[i++] = '*';
		str[i] = '\0';
		nb_times--;
	}

	//show_alloc_mem();

	ft_printf("%s\n", str);

	ft_printf("NB_BLOCK_TINY_TOTAL: %d\n", NB_BLOCK_TINY_TOTAL);
	ft_printf("NB_BLOCK_SMALL_TOTAL: %d\n", NB_BLOCK_SMALL_TOTAL);
	ft_printf("TINY_LEN: %d\n", TINY_LEN);
	ft_printf("TINY_BLOCK_SIZE: %lu\n", TINY_BLOCK_SIZE);
	ft_printf("SMALL_LEN: %d\n", SMALL_LEN);
	ft_printf("SMALL_BLOCK_SIZE: %lu\n", SMALL_BLOCK_SIZE);
	
	ft_printf("%s\n", str);
	return (0);
}
