/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:26:30 by suhshin           #+#    #+#             */
/*   Updated: 2021/03/10 15:28:31 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int pf_type_handler(size_t *i, va_list ap, t_format *st)
{
	if (st->type == 'c')
		return (pf_type_handler_c(va_arg(ap, int), st));
	if (st->type == '%')
		return (pf_type_handler_c('%', st));
	if (st->type == 's')
		return (pf_type_handler_s(va_arg(ap, long long), st));
	if (st->type == 'd' || st->type == 'i')
		return (pf_type_handler_num(va_arg(ap, int), st, BASE, 10));
	if (st->type == 'u')
		return (pf_type_handler_num(va_arg(ap, unsigned int), st, BASE, 10));
	if (st->type == 'x')
		return (pf_type_handler_num(va_arg(ap, unsigned int), st, HEXBASE, 16));
	if (st->type == 'X')
		return (pf_type_handler_num(va_arg(ap, unsigned int), st, HEXBASEL, 16));
	if (st->type == 'p')
		return (pf_type_handler_num(va_arg(ap, long long), st, HEXBASE, 16));
	if (st->type == '\0')
		--(*i);
	return (0);
}

void pf_format_handler(const char *format, size_t *i, va_list ap, t_format *st)
{
	if(format[*i] == '-')
		st->minus = 1;
	else if(st->dot == 0 && format[*i] == '0')
		st->zero = 1;
	else if(st->dot == 0 && format[*i] == '*')
		st->width = pf_asterisk_handler(va_arg(ap, int), st, 1);
	else if(st->dot == 0 && pf_utils_isdigit(format[*i]))
		st->width = pf_utils_atoi(format, i);
	else if(format[*i] == '.')
		st->dot = 1;
	else if(st->dot == 1 && pf_utils_isdigit(format[*i]))
		st->pre = pf_utils_atoi(format, i);
	else if(st->dot == 1 && format[*i] == '*')
		st->pre = pf_asterisk_handler(va_arg(ap, int), st, 0);
}

int pf_asterisk_handler(int num, t_format *st, int i)
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
