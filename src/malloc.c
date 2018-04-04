/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:41:14 by lperret           #+#    #+#             */
/*   Updated: 2018/04/04 15:10:57 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

// TODO: maybe change get_nb_block_user

void	*malloc(size_t size)
{
	void			*ret;

	ret = get_free_block(size);
	return (ret);
}
