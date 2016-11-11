/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 09:22:58 by lperret           #+#    #+#             */
/*   Updated: 2016/11/09 13:25:51 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	tmp = NULL;
	while (*s && s)
	{
		if (*s == (char)c)
			tmp = (char*)s;
		s++;
	}
	if (*s == (char)c)
	tmp = (char*)s;
	return (tmp == NULL ? NULL : tmp);
}
