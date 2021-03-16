/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:26:30 by suhshin           #+#    #+#             */
/*   Updated: 2021/03/10 15:27:45 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void pf_utils_init_struct(t_format *st)
{
	pf_utils_memset(st, 0, sizeof(t_format)); // change to ft_memset
	st->pre = -1;
}

void pf_utils_print_rep(char c, int n)
{
	char *tmp;

	if (n < 0)
		return ;
	tmp = malloc(n + 1);
	if(!tmp)
		return ;
	pf_utils_memset(tmp, c, n);
	tmp[n] = '\0';
	pf_utils_putstr(tmp, 1);
	free(tmp);
	tmp = 0;
}

char pf_utils_width_char(t_format *st)
{
	if (st->type != 'c' && st->type != 's' && st->type != '%')
		return (' ');
	if (st->zero && !st->minus)
		return ('0');
	return (' ');
}

void pf_utils_putflag(t_format *st, int len)
{
	if (st->type == 'X')
		write(1, "0X", len);
	else
		write(1, "0x", len);
	if (st->plus > 0)
		write(1, &st->plus, 1);
}

int pf_utils_addlen(t_format *st)
{
	if (st->type == 'p' || (st->hash && (st->type == 'x' || st->type == 'X')))
		return (2);
	return (0);
}

int pf_utils_return(char **str, int len, t_format *st)
{
	int sign;

	if (!*str)
		return (-1);
	sign = pf_utils_addlen(st);
	pf_utils_print_rep(pf_utils_width_char(st), !st->minus * st->width - len - sign - (st->plus > 0));
	pf_utils_putflag(st, sign);
	pf_utils_putstr(*str, 1);
	pf_utils_print_rep(pf_utils_width_char(st), st->minus * st->width - len - sign - (st->plus > 0));
	free(*str);
	*str = 0;
	return (pf_max(st->width, len + sign + (st->plus > 0)));
}
