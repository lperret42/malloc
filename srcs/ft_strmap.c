/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:42:18 by lperret           #+#    #+#             */
/*   Updated: 2016/11/15 15:23:38 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	char	*cp;

	if (!s || !f)
		return (NULL);
	if (!(new = (char*)ft_memalloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	cp = new;
	while (*s)
		*new++ = (*f)(*s++);
	return (cp);
}
