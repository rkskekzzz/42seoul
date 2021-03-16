/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_handler_s_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:26:30 by suhshin           #+#    #+#             */
/*   Updated: 2021/03/16 22:20:51 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	pf_type_handler_s(char *str, t_format *st)
{
	char	*ret;
	int		len;

	if (st->dot == 1 && st->pre <= 0)
		ret = pf_utils_strdup("");
	else if (str == 0)
		ret = pf_utils_strdup("(null)");
	else
		ret = pf_utils_strdup((char *)str);
	len = pf_utils_strlen(ret);
	if (st->pre != -1)
		len = pf_min(st->pre, len);
	ret[len] = '\0';
	return (pf_utils_return(&ret, len, st));
}
