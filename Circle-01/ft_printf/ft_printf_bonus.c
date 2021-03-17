/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:26:30 by suhshin           #+#    #+#             */
/*   Updated: 2021/03/17 13:56:10 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int		ft_printf(const char *format, ...)
{
	int		print_size;
	va_list	ap;

	va_start(ap, format);
	print_size = pf_printf(format, ap, 0, -1);
	va_end(ap);
	if (print_size < 0)
		return (-1);
	return (print_size);
}

int		pf_printf(const char *format, va_list ap, int print_size, size_t i)
{
	t_format	st;

	while (format[++i] != '\0')
	{
		pf_utils_init_struct(&st);
		if (format[i] == '%')
		{
			while (!pf_utils_istype(format[++i], &st))
				pf_format_handler(format, &i, ap, &st);
			if (st.type == 'n')
				pf_set_n(print_size, ap, &st);
			else
				print_size += pf_type_handler(&i, ap, &st);
		}
		else
			print_size += write(1, &format[i], 1);
	}
	return (print_size);
}

void	pf_set_n(int print_size, va_list ap, t_format *st)
{
	int			*i;
	short int	*s;

	i = 0;
	s = 0;
	if (st->length == 'h')
	{
		s = va_arg(ap, short int *);
		*s = print_size;
	}
	else
	{
		i = va_arg(ap, int *);
		*i = print_size;
	}
}
