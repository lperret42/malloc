/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:56:57 by lperret           #+#    #+#             */
/*   Updated: 2016/11/09 17:35:00 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	while (n > 0 && (*((unsigned char*)(s1 + i))) == (*((unsigned char*)(s2 + i)))
		&& *((unsigned char*)(s1 + i)) && *((unsigned char*)(s2 + i)))
	{
		n--;
		i++;
	}
	//if (n == 0) //&& (*((unsigned char*)(s1 + i))) && (*((unsigned char*)(s2 + i))))
	//	i--;
	return (*((unsigned char *)(s1 + i)) - *((unsigned char *)(s2 + i)));
}
