/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:40:22 by lperret          #+#    #+#             */
/*   Updated: 2017/01/14 22:11:34 by lperret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

static int	ft_check_conv_b(t_print *elem)
{
	if (elem->hashtag
			|| elem->plus
			|| elem->space
			|| elem->zero
			|| elem->precision != -1)
		return (0);
	return (1);
}

static char	*ft_len_alloc(t_print *elem, size_t len)
{
	char	*str;

	str = NULL;
	if (elem->width > (int)len)
		len = elem->width;
	if (!(str = ft_strnew(len)))
		return (NULL);
	ft_memset(str, ' ', len);
	return (str);
}

char		*ft_conv_b(char *str, t_print *elem, va_list ap)
{
	char	*ptr;

	ptr = NULL;
	if (!ft_check_conv_b(elem))
		return (NULL);
	if (!(str = ft_utoa_base(va_arg(ap, int), 2)))
		return (NULL);
	ptr = ft_len_alloc(elem, ft_strlen(str));
	ft_set_digit(ptr, str, elem);
	return (ptr);
}
