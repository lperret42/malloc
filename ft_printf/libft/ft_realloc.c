/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:22:39 by lperret          #+#    #+#             */
/*   Updated: 2016/12/08 19:30:31 by lperret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *s, char *buff, size_t n)
{
	char	*tmp;

	if (!(tmp = ft_strnew(n)))
		return (NULL);
	ft_strcpy(tmp, s);
	ft_strcat(tmp, buff);
	free(s);
	s = tmp;
	return (s);
}
