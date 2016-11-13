/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:48:22 by lperret           #+#    #+#             */
/*   Updated: 2016/11/13 15:22:38 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_digit(int n)
{
	int nb;

	if (n < 0)
		n = -n;
	nb = 1;
	while (n >= 10)
	{
		nb++;
		n = n / 10;
	}
	return (nb);
}

static char	*is_min_int(void)
{
	char	*new;

	if (!(new = ft_memalloc(sizeof(*new) * 12)))
		return (NULL);
	new[0] = '-';
	new[1] = '2';
	new[2] = '1';
	new[3] = '4';
	new[4] = '7';
	new[5] = '4';
	new[6] = '8';
	new[7] = '3';
	new[8] = '6';
	new[9] = '4';
	new[10] = '8';
	new[11] = '\0';
	return (new);
}

char		*ft_itoa(int n)
{
	int		nb_digit;
	char	*new;

	if (n == -2147483648)
		return (is_min_int());
	nb_digit = ft_nb_digit(n);
	if (n < 0)
		nb_digit++;
	if (!(new = ft_memalloc(sizeof(*new) * (nb_digit + 1))))
		return (NULL);
	if (n < 0)
	{
		new[0] = '-';
		n = -n;
	}
	new[nb_digit] = '\0';
	nb_digit--;
	while (nb_digit > 0)
	{
		new[nb_digit--] = n % 10 + '0';
		n = n / 10;
	}
	if (new[0] != '-')
		new[0] = n % 10 + '0';
	return (new);
}
