/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:33:07 by lperret           #+#    #+#             */
/*   Updated: 2016/11/10 18:28:51 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
	
	/*//itoa
	int n_itoa = -2147483648;
	printf("%s\n", ft_itoa(n_itoa));*/

	//strsplit
	char	*s_strspplit = "helloworld";
	//char	*s_strspplit = "split this for me";
	char	c_strsplit = ' ';
	char	**test;
	test = ft_strsplit(s_strspplit, c_strsplit);
	int n = 0;
	int i = 0;
	while (i <= n)
	{
		printf("%s\n", test[i]);
		i++;
	}


	/*char	*s = "Bonjour";
	ft_striter(s, &ft_putstr);*/

	//putchar
	//ft_putchar(-80);

	/*//memcmp
	//const char	*s1_memcmp = "\xff\xaa\xde\x12";
	//const char	*s2_memcmp = "\xff\xaa\xde\x12MACOSAAAAA";
	const char	*s1_memcmp = "\xff\0\0\xaa\0\xde\xffMACOSx\xff";
	const char	*s2_memcmp = "\xff\0\0\xaa\0\xde\x00MBS";
	size_t		n_memcmp = 9;
	int			char_to_test = 8;
	printf("%c\n", s1_memcmp[char_to_test]);
	printf("%c\n", s2_memcmp[char_to_test]);
	printf("%d\n", ft_memcmp(s1_memcmp, s2_memcmp, n_memcmp));
	printf("%d\n", memcmp(s1_memcmp, s2_memcmp, n_memcmp));*/

	/*char	*b;
	unsigned char *tmp;
	int		c = 100;
	size_t	len = 50;
	b = (char*)malloc(len);
	tmp = memset(b, c, len);
	printf("%d\n", tmp[2]);
	tmp = memset(b, c, len);
	printf("%d\n", tmp[2]);*/

	/*int n_alpha = 10000000;
	printf("%d\n", isalpha(n_alpha));
	printf("%d\n", ft_isalpha(n_alpha));*/

	/*char	dst_strncpy[] = "BONJOURTOUTLEMONDE";
	char	src_strncpy[] = "HELLOWORLD";
	strncpy(dst_strncpy, src_strncpy, 15);
	printf("%c\n", dst_strncpy[13]);
	printf("%s\n\n", src_strncpy);*/

	/*char n_atoi[] = "-2147483648";
	printf("%d\n", ft_atoi(((void*)0)));
	printf("%d\n\n", atoi(((void*)0)));*/

	/*int c = 97;
	char s[] = "kjdhfgaor";
	printf("%p\n", ft_strchr(s, c));
	printf("%p\n\n", strchr(s, c));*/

	/*int c = 'a';
	char s[] = "kjadhfgaor";
	printf("%p\n", strrchr(s, c));
	printf("%p\n", ft_strrchr(s, c));
	return (0);*/

	/*const char *big = alut*les***etudiants*";
	const char *little = "";
	printf("%p\n", strstr(big, little));
	printf("%p\n", ft_strstr(big, little));

	int len = 7;
	printf("%p\n", strnstr(big, little, len));
	printf("%p\n", ft_strnstr(big, little, len));*/

	/*int n = -2147483648;
	ft_putnbr(n);
	ft_putchar('\n');
	return (0);*/

	//ft_strdup
	/*char	*s_strdup = NULL;
	ft_strdup(s_strdup);
	strdup(s_strdup);*/

	//ft_strlcat
	/*char		dst_strlcat[100] = "helloo";
	char		dst2_strlcat[100] = "helloo";
	const char	*src_strlcat = "Tout le monde";
	size_t		size_strlcat = 5;
	printf("%zu\n", strlcat(dst_strlcat, src_strlcat, size_strlcat));
	printf("%s\n", dst_strlcat);
	printf("%zu\n", ft_strlcat(dst2_strlcat, src_strlcat, size_strlcat));
	printf("%s\n", dst2_strlcat);*/
	return (0);
}
