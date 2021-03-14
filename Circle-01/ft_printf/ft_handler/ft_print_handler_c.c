/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_handler_c.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:26:30 by suhshin           #+#    #+#             */
/*   Updated: 2021/03/10 15:28:37 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int pf_type_handler_c(char ch, t_format *st)
{
	pf_utils_print_rep(pf_utils_width_char(st), !st->minus * st->width - 1);
	pf_utils_putchar(ch, 1);
	pf_utils_print_rep(pf_utils_width_char(st), st->minus * st->width - 1);
	return (pf_max(st->width, 1));
}
