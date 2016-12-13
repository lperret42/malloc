/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:39:05 by lperret           #+#    #+#             */
/*   Updated: 2016/11/15 14:49:14 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	int		find;
	size_t	little_len;
	size_t	cp_len;

	if (*little == '\0')
		return ((char*)big);
	i = 0;
	little_len = ft_strlen(little);
	cp_len = len;
	while (big[i] && (len-- - (little_len - 1) > 0))
	{
		find = 1;
		j = -1;
		while (little[++j])
			if (big[i + j] != little[j])
				find = 0;
		if (find && little_len <= cp_len)
			return ((char*)(big + i));
		i++;
	}
	return (NULL);
}
