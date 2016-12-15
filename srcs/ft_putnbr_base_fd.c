/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:58:45 by lperret           #+#    #+#             */
/*   Updated: 2016/11/13 15:20:40 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_fd(int n, int base, int fd)
{
	long	tmp;

	tmp = (long)n;
	if (tmp < 0)
	{
		tmp = -tmp;
		ft_putchar_fd('-', fd);
	}
	if (tmp >= base)
		ft_putnbr_base_fd(tmp / base,base,fd);
	if (tmp % base >= 10)
		ft_putchar_fd(tmp % base + 55, fd);
	else
		ft_putchar_fd(tmp % base + '0', fd);
}
