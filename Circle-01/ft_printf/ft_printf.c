/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:26:30 by suhshin           #+#    #+#             */
/*   Updated: 2021/03/10 15:27:33 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char* format, ...)
{
	int print_size;
	va_list ap;

	va_start(ap, format);
	print_size = pf_printf(format, ap);
	va_end(ap);
	if (print_size < 0)
		return (-1);
	return (print_size);
}

int		pf_printf(const char *format, va_list ap)
{
	size_t i;
	int print_size;
	t_format st;

	i = 0;
	print_size = 0;
	while (format[i] != '\0')
	{
		pf_utils_init_struct(&st);
		if (format[i] == '%')
		{
			while (!pf_utils_istype(format[++i], &st))
				pf_format_handler(format, &i, ap, &st);
			print_size += pf_type_handler(&i, ap, &st);
		}
		else
		{
			pf_utils_putchar(format[i], 1);
			++print_size;
		}
		++i;
	}
	return (print_size);
}
