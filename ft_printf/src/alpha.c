/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 13:55:04 by lperret          #+#    #+#             */
/*   Updated: 2017/01/31 12:33:39 by lperret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

char	*ft_set_alpha(t_print *elem, size_t len)
{
	int		nb;
	char	*ret;

	nb = 0;
	if (elem->width > (int)len)
		nb = elem->width - (int)len;
	if (!(ret = ft_strnew(nb)))
		return (NULL);
	ft_memset(ret, ' ', nb);
	return (ret);
}
