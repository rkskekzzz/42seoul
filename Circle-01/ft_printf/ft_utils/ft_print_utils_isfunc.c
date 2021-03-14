/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_isfunc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:26:30 by suhshin           #+#    #+#             */
/*   Updated: 2021/03/10 15:27:58 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int pf_utils_istype(char ch, t_format *st)
{
	if (ch == 'c' || ch == 's' || ch == 'p' || ch == 'd' || \
		ch == 'i' || ch == 'u' || ch == 'x' || ch == 'X' || \
		ch == '%' || ch == '\0')
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

