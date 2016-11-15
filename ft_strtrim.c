/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:31:58 by lperret           #+#    #+#             */
/*   Updated: 2016/11/15 15:16:41 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	size_t	i;
	size_t	j;
	size_t	l;
	size_t	size;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = l - 1;
	while (j > i && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j--;
	size = j - i + 1;
	if (!(new = (char*)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	j = 0;
	while (j < size)
	{
		new[j] = s[i + j];
		j++;
	}
	return (new);
}
