/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:12:15 by lperret           #+#    #+#             */
/*   Updated: 2016/12/13 14:13:45 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		pos_endl(char *s)
{
	int		i;

	if (s == NULL)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int		ft_read(t_file *content)
{
	char	*tmp;
	char	*buf;

	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((content->pos = pos_endl(content->res)) == -1 &&
	(content->nb_char_read = read(content->fd, buf, BUFF_SIZE)) != 0)
	{
		if (!(content->res))
			content->res = ft_strdup(buf);
		else
		{
			tmp = content->res;
			content->res = ft_strjoin(content->res, buf);
			free(tmp);
		}
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	free(buf);
	if (!(content->res) && content->nb_char_read == 0)
		return (0);
	return (1);
}

int				get_line(t_file *content, char **line)
{
	int		ret_read;
	char	*tmp;

	if ((ret_read = ft_read(content)) != 1)
		return (ret_read);
	if (content->nb_char_read == 0)
		if (ft_strlen(content->res) == 0)
		{
			*line = NULL;
			return (0);
		}
	if (content->pos != -1)
		content->res[content->pos] = '\0';
	*line = ft_strnew(ft_strlen(content->res));
	free(*line);
	*line = ft_strdup(content->res);
	tmp = content->res;
	if (content->pos != -1)
		content->res = ft_strdup(content->res + content->pos + 1);
	else
		content->finish = 1;
	free(tmp);
	return (1);
}

t_file			*add_end_if(t_file *begin_list, int fd)
{
	t_file		*tmp;
	t_file		*new;

	tmp = begin_list;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (begin_list);
		tmp = tmp->next;
	}
	tmp = begin_list;
	while (tmp->next)
		tmp = tmp->next;
	if (!(new = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	new->fd = fd;
	new->pos = 0;
	new->nb_char_read = 0;
	new->finish = 0;
	new->res = NULL;
	new->next = NULL;
	tmp->next = new;
	return (begin_list);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*begin_list = NULL;
	t_file			*content;

	if (line == NULL || read(fd, "0", 0) == -1)
		return (-1);
	if (begin_list == NULL)
	{
		if (!(begin_list = (t_file*)malloc(sizeof(t_file))))
			return (-1);
		begin_list->fd = fd;
		begin_list->pos = 0;
		begin_list->nb_char_read = 0;
		begin_list->finish = 0;
		begin_list->res = NULL;
		begin_list->next = NULL;
	}
	if (!(begin_list = add_end_if(begin_list, fd)))
		return (-1);
	content = begin_list;
	while (content->fd != fd)
		content = content->next;
	if (content->finish == 1)
		return (0);
	return (get_line(content, line));
}
