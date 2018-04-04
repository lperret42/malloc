#include "malloc.h"

// TODO print error message, norm, add realloc and show_alloc_mem and exaustive tests

int		main(void)
{
	size_t		i;
	long int	n;
	int			nb_times;
	char		*str;
	char		*str2;

	show_alloc_mem();
	str = malloc(0);
	printf("str: %p\n", str);
	show_alloc_mem();
	str = realloc(str, 8);
	show_alloc_mem();
	printf("str: %p\n", str);
	//return 0;
	str = malloc(50);
	show_alloc_mem();
	printf("str: %p\n", str);
	str = realloc(str, 10);
	show_alloc_mem();
	printf("str: %p\n", str);
	//return 0;
	str = malloc(0);
	str = malloc(5);
	free(str);
	printf("hello3\n");
	str = malloc(42);
	str = malloc(100);
	str = malloc(40000);
	show_alloc_mem();
	nb_times = 5000;
	n = 10;
	str = NULL;
	//return 0;
	while (nb_times > 0)
	{
		//free(str);
		str = (char*)malloc(n + 1);
		//str = (char*)realloc(NULL, n + 1);
		printf("str: %p\n", str);
		printf("nb_times: %d, str: %p\n", nb_times, str);
		if (str == NULL)
			return -1;
		i = 0;
		while (i < n && i > 0)
			str[i++] = '*';
		str[i] = '\0';
		nb_times--;
		show_alloc_mem();
	}

	printf("%s\n", str);
	
	printf("NB_BLOCK_TINY_TOTAL: %d\n", NB_BLOCK_TINY_TOTAL);
	printf("NB_BLOCK_SMALL_TOTAL: %d\n", NB_BLOCK_SMALL_TOTAL);
	printf("TINY_LEN: %d\n", TINY_LEN);
	printf("TINY_BLOCK_SIZE: %lu\n", TINY_BLOCK_SIZE);
	printf("SMALL_LEN: %d\n", SMALL_LEN);
	printf("SMALL_BLOCK_SIZE: %lu\n", SMALL_BLOCK_SIZE);
	
	printf("%s\n", str);
	return (0);
}
