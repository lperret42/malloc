/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_toa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:31:35 by lperret          #+#    #+#             */
/*   Updated: 2017/01/19 19:34:11 by lperret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

char		*ft_ulotoa_base(unsigned long long int nb, int base)
{
	unsigned long long int	tmp;
	int						size;
	char					*set;
	char					*str;

	tmp = nb;
	size = 0;
	set = "0123456789abcdef";
	if (base <= 0 || base > 16)
		return (NULL);
	while (tmp /= base)
		size++;
	if (!(str = ft_strnew(++size)))
		return (NULL);
	while (size--)
	{
		str[size] = set[nb % base];
		nb /= base;
	}
	return (str);
}

char		*ft_utoa_base(unsigned int nb, int base)
{
	unsigned int	tmp;
	int				size;
	char			*set;
	char			*str;

	tmp = nb;
	size = 0;
	set = "0123456789abcdef";
	if (base <= 0 || base > 16)
		return (NULL);
	while (tmp /= base)
		size++;
	if (!(str = ft_strnew(++size)))
		return (NULL);
	while (size--)
	{
		str[size] = set[nb % base];
		nb /= base;
	}
	return (str);
}

char		*ft_ushotoa_base(unsigned short int nb, int base)
{
	unsigned short int	tmp;
	int					size;
	char				*set;
	char				*str;

	tmp = nb;
	size = 0;
	set = "0123456789abcdef";
	if (base <= 0 || base > 16)
		return (NULL);
	while (tmp /= base)
		size++;
	if (!(str = ft_strnew(++size)))
		return (NULL);
	while (size--)
	{
		str[size] = set[nb % base];
		nb /= base;
	}
	return (str);
}

char		*ft_uchatoa_base(unsigned char nb, int base)
{
	unsigned char		tmp;
	int					size;
	char				*set;
	char				*str;

	tmp = nb;
	size = 0;
	set = "0123456789abcdef";
	if (base <= 0 || base > 16)
		return (NULL);
	while (tmp /= base)
		size++;
	if (!(str = ft_strnew(++size)))
		return (NULL);
	while (size--)
	{
		str[size] = set[nb % base];
		nb /= base;
	}
	return (str);
}
