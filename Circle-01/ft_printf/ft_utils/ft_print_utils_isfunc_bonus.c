/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_isfunc_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:26:30 by suhshin           #+#    #+#             */
/*   Updated: 2021/03/16 22:19:59 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	pf_utils_istype(char ch, t_format *st)
{
	if (ch == 'c' || ch == 's' || ch == 'p' || ch == 'd' ||
		ch == 'i' || ch == 'u' || ch == 'x' || ch == 'X' ||
		ch == '%' || ch == 'n' || ch == '\0')
	{
		st->type = ch;
		return (1);
	}
	return (0);
}

int	pf_utils_isdigit(char ch)
{
	return (ch >= '0' && ch <= '9');
}
