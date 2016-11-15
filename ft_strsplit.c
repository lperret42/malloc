/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:08:42 by lperret           #+#    #+#             */
/*   Updated: 2016/11/15 15:18:03 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	if (!(new_word = ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_word[i] = s[start + i];
		i++;
	}
	new_word[i] = '\0';
	return (new_word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**new;
	int		nb_word;
	int		n;
	int		i;

	if (!s)
		return (NULL);
	nb_word = ft_nb_word(s, c);
	if (!(new = ft_memalloc(sizeof(char*) * (nb_word + 1))))
		return (NULL);
	n = 0;
	i = 0;
	while (n < nb_word)
	{
		if (s[i] != c)
		{
			new[n++] = ft_new_word(s, i, ft_size_word(s, i, c));
			i += ft_size_word(s, i, c);
		}
		else
			while (s[i] && s[i] == c)
				i++;
	}
	new[n] = NULL;
	return (new);
}
