/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:26:30 by suhshin           #+#    #+#             */
/*   Updated: 2021/03/16 21:53:38 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define BASE "0123456789"
# define HEXBASE "0123456789abcdef"
# define HEXBASEL "0123456789ABCDEF"

typedef	struct	s_format
{
	int			plus;
	int			minus;
	int			zero;
	int			width;
	int			dot;
	int			pre;
	int			space;
	int			hash;
	int			type;
}				t_format;

int				ft_printf(const char *format, ...);
int				pf_printf(const char *format, va_list ap, int print_size);
int				pf_type_handler(size_t *i, va_list ap, t_format *st);
void			pf_format_handler(const char *format, size_t *i,
		va_list ap, t_format *st);
int				pf_asterisk_handler(int num, t_format *st, int i);

int				pf_type_handler_c(char ch, t_format *st);
int				pf_type_handler_s(char *str, t_format *st);
int				pf_type_handler_n(long long num, t_format *st,
		const char *base, int bs);
void			pf_utils_init_struct(t_format *st);
void			pf_utils_print_rep(char c, int n);
int				pf_utils_return(char **str, int len, t_format *st);
char			pf_utils_width_char(t_format *st);
int				pf_utils_atoi(const char *format, size_t *i);
char			*pf_utils_itoa(long long num, const char *base,
		int bs, t_format *st);
int				pf_utils_istype(char ch, t_format *st);
int				pf_utils_isdigit(char ch);
int				pf_max(int a, int b);
int				pf_min(int a, int b);
int				pf_utils_numlen(long long num, int base);
long long		pf_utils_abs(long long n);
size_t			pf_utils_strlen(const char *str);
char			*pf_utils_strdup(const char *src);
void			*pf_utils_memset(void *dest, int value, size_t size);
void			pf_utils_putstr(char *s, int fd);
void			pf_utils_putchar(char c, int fd);
void			*pf_utils_memcpy(void *dest, const void *src, size_t size);

#endif
