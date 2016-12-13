/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:15:26 by lperret           #+#    #+#             */
/*   Updated: 2016/11/15 15:57:53 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*to_return;
	t_list	*tmpret;
	t_list	*tmplst;

	if (!lst || !f)
		return (NULL);
	tmplst = (*f)(lst);
	if ((to_return = ft_lstnew(tmplst->content, tmplst->content_size)))
	{
		tmpret = to_return;
		lst = lst->next;
		while (lst != NULL)
		{
			tmplst = (*f)(lst);
			if (!(tmpret->next =
						ft_lstnew(tmplst->content, tmplst->content_size)))
				return (NULL);
			tmpret = tmpret->next;
			lst = lst->next;
		}
		tmpret->next = NULL;
	}
	return (to_return);
}
