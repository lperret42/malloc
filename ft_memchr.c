/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:44:45 by lperret           #+#    #+#             */
/*   Updated: 2016/11/10 12:35:02 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	to_find;

	to_find = (unsigned char)c;
	while (*((unsigned char *)s) != to_find && *((unsigned char*)s) && n-- > 0)
		s++;
	return (*((unsigned char*)s) == to_find ? (void*)s : NULL);
}
