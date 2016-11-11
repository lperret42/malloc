/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:08:42 by lperret           #+#    #+#             */
/*   Updated: 2016/11/10 18:39:34 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int		ft_nb_word(char const *s, char c)
{
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			nb++;
		}
		else
			while (s[i] == c && s[i])
				i++;
	}
	return (nb);
}

static int		ft_nb_char(char const *s, char c)
{
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	while (s[i])
		if (s[i++] != c)
			nb++;
	return (nb);
}

static int		ft_size_word(char const *s, int start, char c)
{
	int		nb;

	nb = 0;
	while (s[start] && s[start] != c)
	{
		start++;
		nb++;
	}
	return (nb);
}

static char		*ft_new_word(char const *s, int start, int len)
{
	char	*new_word;
	int		i;

	//printf("%c\n", s[start]);
	//printf("%d\n", len);
	if (!(new_word = ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_word[i] = s[start + i];
		i++;
	}
	new_word[i] = '\0';
	//printf("%d\n", i);
	//printf("%s\n", new_word);
	return (new_word);
}

char			**ft_strsplit(char const *s, char c)
{
	//printf("%d\n", ft_nb_word(s, c));
	//printf("%d\n", ft_nb_char(s, c));
	char	**new;
	int		nb_word;
	int		nb_char;
	int		n;
	int		i;

	nb_word = ft_nb_word(s, c);
	nb_char = ft_nb_char(s, c);
	if (!(new = ft_memalloc(sizeof(char) * (nb_word + nb_char + 1))))
		return (NULL);
	n = 0;
	i = 0;
	while (n < nb_word)
	{
		while (s[i])
		{
			if (s[i] != c)
			{
				//printf("%d\n", n);
				new[n] = ft_new_word(s, i, ft_size_word(s, i, c));
				/*printf("%d\n", ft_size_word(s, i, c));
				printf("%s\n", new[n]);*/
				i += ft_size_word(s, i, c);
				n++;
			}
			else
				while (s[i] && s[i] == c)
					i++;
		}
		//printf("%d\n", n);
	}
	//printf("%d\n", i);//ft_size_word(s, i, c));
	new[n] = ft_new_word(s, i, ft_size_word(s, i, c));
	return (new);
}
