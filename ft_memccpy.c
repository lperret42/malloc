/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:20:01 by lperret           #+#    #+#             */
/*   Updated: 2016/11/10 14:15:24 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;

	c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		*(((unsigned char*)dst) + i) = *(((unsigned char*)src) + i);
		if (*(((unsigned char*)dst) + i) == c)
			return (((unsigned char*)dst) + i + 1);
		i++;
	}
	return (NULL);
}
