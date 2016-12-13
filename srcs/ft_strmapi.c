/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:55:30 by lperret           #+#    #+#             */
/*   Updated: 2016/11/15 15:24:01 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	char			*cp;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	if (!(new = (char*)ft_memalloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	cp = new;
	i = 0;
	while (*s)
		*new++ = (*f)(i++, *s++);
	return (cp);
}
