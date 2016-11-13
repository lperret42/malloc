/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:56:57 by lperret           #+#    #+#             */
/*   Updated: 2016/11/13 15:09:57 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n - 1 &&
			*((unsigned char *)(s1 + i)) == *((unsigned char *)(s2 + i)))
		i++;
	return ((unsigned char)*((unsigned char *)(s1 + i)) -
			*((unsigned char *)(s2 + i)));
}
