/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:44:45 by lperret           #+#    #+#             */
/*   Updated: 2016/11/15 11:58:42 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	to_find;
	unsigned char	*s2;

	to_find = (unsigned char)c;
	s2 = (unsigned char *)s;
	while (n--)
	{
		if (*s2 == to_find)
			return (s2);
		s2++;
	}
	return (NULL);
}
