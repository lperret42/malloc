//#include "malloc.h"
#include <stdlib.h>
#include <stdio.h>

// TODO print error message, norm, add realloc and show_alloc_mem and exaustive tests

int		main(void)
{
	size_t		i;
	long int	n;
	int			nb_times;
	char		*str;
	char		*str2;

	str = malloc(1);
	str[10000000] = 42;
	printf("str: %p\n", str);
	str = realloc(str, 14);
	printf("str: %p\n", str);
	return 0;
	//str[0] = 55;
	//free(str);
	//str = (char*)0x456631332;
	printf("str: %p\n", str);
	printf("hello\n");
	str = realloc(str, 56);
	printf("hello2\n");
	str = malloc(0);
	str = malloc(5);
	free(str);
	//free(str);
	printf("hello3\n");
	str = malloc(42);
	str = malloc(100);
	str = malloc(40000);
	nb_times = 50000;
	n = 50;
	str = NULL;
	while (nb_times > 0)
	{
		free(str);
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
	/*
	printf("NB_BLOCK_TINY_TOTAL: %d\n", NB_BLOCK_TINY_TOTAL);
	printf("NB_BLOCK_SMALL_TOTAL: %d\n", NB_BLOCK_SMALL_TOTAL);
	printf("TINY_LEN: %d\n", TINY_LEN);
	printf("TINY_BLOCK_SIZE: %lu\n", TINY_BLOCK_SIZE);
	printf("SMALL_LEN: %d\n", SMALL_LEN);
	printf("SMALL_BLOCK_SIZE: %lu\n", SMALL_BLOCK_SIZE);
	*/
	printf("%s\n", str);
	return (0);
}
