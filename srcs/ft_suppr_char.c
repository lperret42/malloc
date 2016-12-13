/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_suppr_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 13:59:34 by lperret           #+#    #+#             */
/*   Updated: 2016/11/29 14:34:44 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_suppr_char(char *str, char c)
{
	char	*tmp;
	char	*ret;
	int		nb;
	int		i;
	int		j;

	tmp = ft_strdup(str);
	nb = 0;
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == c)
		{
			j = i;
			while (tmp[j++] != '\0')
				tmp[j - 1] = tmp[j];
			nb++;
		}
		else
			i++;
	}
	tmp[ft_strlen(str) - nb] = '\0';
	ret = ft_strdup(tmp);
	free(tmp);
	return (ret);
}
