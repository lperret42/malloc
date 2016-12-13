/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:13:37 by lperret           #+#    #+#             */
/*   Updated: 2016/12/11 15:54:49 by lperret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

# include <fcntl.h>
# include "libft.h"

typedef struct		s_file
{
	int				fd;
	int				pos;
	int				nb_char_read;
	int				finish;
	char			*res;
	struct s_file	*next;
}					t_file;

int					get_next_line(const int fd, char **line);

#endif
