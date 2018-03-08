/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 17:59:28 by aparrot           #+#    #+#             */
/*   Updated: 2017/04/30 14:19:25 by aparrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putcolor(const char *s, const char *color)
{
	ft_putstr(color);
	ft_putstr(s);
	ft_putstr(RESET);
}
