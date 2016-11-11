/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:54:50 by lperret           #+#    #+#             */
/*   Updated: 2016/11/08 11:34:16 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;
	int		find;

	if (*big == '\0' && *little == '\0')
		return ((char*)big);
	i = 0;
	while (big[i])
	{
		find = 1;
		j = 0;
		while (little[j])
		{
			if (big[i + j] != little[j])
				find = 0;
			j++;
		}
		if (find)
			return ((char*)&big[i]);
		i++;
	}
	return (NULL);
}
