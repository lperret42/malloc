/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 10:39:11 by lperret          #+#    #+#             */
/*   Updated: 2017/01/31 20:02:18 by lperret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <wchar.h>

typedef struct		s_print
{
	int				hashtag;
	int				zero;
	int				minus;
	int				plus;
	int				space;
	int				width;
	int				precision;
	int				type;
	int				neg;
	int				len;
	int				next;
	intmax_t		putf;
	int				boolutf;
	char			char_conv;
}					t_print;

int					ft_printf(const char *format, ...);

char				*ft_conv_cutf(wchar_t utf, t_print *elem);
char				*ft_conv_sutf(va_list ap, t_print *elem);

char				*ft_conv_c(char *str, t_print *elem, va_list ap);
char				*ft_conv_s(char *str, t_print *elem, va_list ap);
char				*ft_conv_d(char *str, t_print *elem, va_list ap);
char				*ft_conv_u(char *str, t_print *elem, va_list ap);
char				*ft_conv_o(char *str, t_print *elem, va_list ap);
char				*ft_conv_x(char *str, t_print *elem, va_list ap);
char				*ft_conv_b(char *str, t_print *elem, va_list ap);
char				*ft_conv_p(char *str, t_print *elem, va_list ap);
char				*ft_conv_percent(char *str, t_print *elem, va_list ap);

char				*ft_parse_flags(char *cpy, t_print *elem);
char				*ft_parse_width(char *cpy, t_print *elem);
char				*ft_parse_precision(char *cpy, t_print *elem);
char				*ft_parse_type(char *cpy, t_print *elem);
int					ft_parse_conversion(char c, t_print *elem);

char				*ft_set_alpha(t_print *elem, size_t len);
intmax_t			ft_multicast(va_list ap, t_print *elem);
void				ft_set_digit(char *ptr, char *str, t_print *elem);
char				*ft_root(char *format, va_list ap, t_print *elem);
int					ft_printf(const char *format, ...);

void				ft_get_plus_d(char *ptr, char *ptr_ptr, t_print *elem);
void				ft_get_hash_o(char *ptr, char *ptr_ptr, t_print *elem);
void				ft_get_hash_x(char *ptr, char *ptr_ptr, t_print *elem);
void				ft_get_ox(char *ptr, t_print *elem);

char				*ft_wild_format(char *cpy, t_print *elem);
char				*ft_cutter(char *format, t_print *elem);
char				*ft_freezer(char *str);

char				*ft_uchatoa_base(unsigned char nb, int base);
char				*ft_ushotoa_base(unsigned short int nb, int base);
char				*ft_utoa_base(unsigned int nb, int base);
char				*ft_ulotoa_base(unsigned long long int nb, int base);
char				*ft_slotoa_base(long long int nb, int base, t_print *elem);

char				*ft_join_memory_free_all_bis(char *s1, char *s2,
		size_t size, t_print *elem);
char				*ft_join_memory_free_all(char *s1, char *s2, t_print *elem);
char				*ft_join_memory_free_some(char *s1, char *s2,
		t_print *elem);
char				*ft_join_and_free_all(char *s1, char *s2);
char				*ft_strndcpy(char *dst, char *src);

#endif
