/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 13:26:58 by lperret          #+#    #+#             */
/*   Updated: 2017/01/27 16:30:52 by lperret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

char	*ft_conv_percent(char *str, t_print *elem, va_list ap)
{
	char	*ptr;

	ptr = NULL;
	(void)ap;
	if (!(str = ft_strnew(1)))
		return (NULL);
	str[0] = '%';
	if (elem->width > 1 && elem->minus == 0)
	{
		ptr = ft_set_alpha(elem, 1);
		str = ft_join_and_free_all(ptr, str);
	}
	else
	{
		ptr = ft_set_alpha(elem, 1);
		str = ft_join_and_free_all(str, ptr);
	}
	return (str);
}
