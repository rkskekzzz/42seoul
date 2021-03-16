/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_handler_n_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:26:30 by suhshin           #+#    #+#             */
/*   Updated: 2021/03/16 22:20:46 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	pf_type_handler_n(long long num, t_format *st, const char *base, int bs)
{
	char	*ret;

	if (num < 0)
	{
		st->pre += 1;
		st->plus = 0;
	}
	if (num == 0)
		st->hash = 0;
	if (st->zero == 1 && st->dot == 0 && st->minus == 0)
		st->pre = st->width - st->hash - (st->plus > 0);
	if (num == 0 && st->dot == 1 && st->pre <= 0)
		ret = pf_utils_strdup("");
	else if (num == 0 && st->type == 'p' && st->pre <= 0)
		ret = pf_utils_strdup("0");
	else
		ret = pf_utils_itoa(num, base, bs, st);
	return (pf_utils_return(&ret, pf_utils_strlen(ret), st));
}
