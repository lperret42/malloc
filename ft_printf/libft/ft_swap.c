/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:54:52 by lperret          #+#    #+#             */
/*   Updated: 2016/11/17 18:03:46 by lperret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *a, void *b)
{
	unsigned char c;

	c = *(unsigned char *)a;
	*(unsigned char *)a = *(unsigned char *)b;
	*(unsigned char *)b = c;
}
