/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:26:30 by suhshin           #+#    #+#             */
/*   Updated: 2021/03/17 13:58:40 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_type_handler(size_t *i, va_list ap, t_format *st)
{
	if (st->type == 'c')
		return (pf_type_handler_c(va_arg(ap, int), st));
	if (st->type == '%')
		return (pf_type_handler_c('%', st));
	if (st->type == 's')
		return (pf_type_handler_s(va_arg(ap, char *), st));
	if (st->type == 'd' || st->type == 'i')
		return (pf_type_handler_n(va_arg(ap, int), st, BASE, 10));
	if (st->length == 'h')
		return (pf_length_handler(ap, st));
	if (st->type == 'u')
		return (pf_type_handler_n(va_arg(ap, unsigned int), st, BASE, 10));
	if (st->type == 'x')
		return (pf_type_handler_n(va_arg(ap, unsigned int), st, HEXBASE, 16));
	if (st->type == 'X')
		return (pf_type_handler_n(va_arg(ap, unsigned int), st, HEXBASEL, 16));
	if (st->type == 'p')
		return (pf_type_handler_n(va_arg(ap, long long), st, HEXBASE, 16));
	if (st->type == '\0')
		--(*i);
	return (0);
}

void	pf_format_handler(const char *str, size_t *i, va_list ap, t_format *st)
{
	if (str[*i] == '-')
		st->minus = 1;
	else if (str[*i] == '#')
		st->hash = 2;
	else if (str[*i] == '+')
		st->plus = '+';
	else if (str[*i] == ' ')
		st->plus = ' ';
	else if (st->dot == 0 && str[*i] == '0')
		st->zero = 1;
	else if (st->dot == 0 && str[*i] == '*')
		st->width = pf_asterisk_handler(va_arg(ap, int), st, 1);
	else if (st->dot == 0 && pf_utils_isdigit(str[*i]))
		st->width = pf_utils_atoi(str, i);
	else if (str[*i] == '.')
		st->dot = 1;
	else if (st->dot == 1 && pf_utils_isdigit(str[*i]))
		st->pre = pf_utils_atoi(str, i);
	else if (st->dot == 1 && str[*i] == '*')
		st->pre = pf_asterisk_handler(va_arg(ap, int), st, 0);
	else if (str[*i] == 'h')
		st->length = str[*i];
}

int		pf_length_handler(va_list ap, t_format *st)
{
	unsigned short int	num;

	num = va_arg(ap, int);
	if (st->type == 'u')
		return (pf_type_handler_n(num, st, BASE, 10));
	if (st->type == 'x')
		return (pf_type_handler_n(num, st, HEXBASE, 16));
	if (st->type == 'X')
		return (pf_type_handler_n(num, st, HEXBASEL, 16));
	return (0);
}

int		pf_asterisk_handler(int num, t_format *st, int i)
{
	if (num >= 0)
		return (num);
	if (i)
	{
		st->minus = 1;
		return (-num);
	}
	st->dot = 0;
	return (-1);
}
