/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:19:49 by lperret           #+#    #+#             */
/*   Updated: 2016/11/09 15:43:30 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dst, const void *src, size_t len)
{
	/*void	*cp;
	size_t	diff;

	cp = dst;
	diff = (src - dst);
	if (diff < len)
		len = diff;*/
	while (len-- > 0) // && (diff--) != 0)
		((unsigned char*)dst)[len] = ((unsigned char*)src)[len];
	return (dst);
}
