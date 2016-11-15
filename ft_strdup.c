/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:28:19 by lperret           #+#    #+#             */
/*   Updated: 2016/11/09 11:04:01 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		i;
	int		s1_len;

	s1_len = ft_strlen(s1);
	if (!(new = (char*)malloc(sizeof(*new) * (s1_len + 1))))
		return (NULL);
	i = 0;
	while (i <= s1_len)
	{
		new[i] = s1[i];
		i++;
	}
	return (new);
}
