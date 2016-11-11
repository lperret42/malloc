/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:05:40 by lperret           #+#    #+#             */
/*   Updated: 2016/11/09 18:12:16 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	char	*cp;

	if (!(new = (char*)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	cp = new;
	while (len-- > 0)
		*new++ = *(s + start++);
	*new = '\0';
	return (cp);
}
