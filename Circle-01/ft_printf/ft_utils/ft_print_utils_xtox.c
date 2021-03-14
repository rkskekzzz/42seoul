/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_xtox.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:26:30 by suhshin           #+#    #+#             */
/*   Updated: 2021/03/10 15:28:18 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_utils_atoi(const char *format, size_t *i)
{
	long long	ret;
	long long	tmp;
	int			is_of;

	ret = 0;
	is_of = 0;
	while (pf_utils_isdigit(format[*i]))
	{
		tmp = ret * 10 + (format[*i] - '0');
		if ((((1 << 31) & tmp) ^ ((1 << 31) & ret)) == 0)
			is_of = 1;
		ret = tmp;
		++(*i);
	}
	--(*i);
	if (is_of && ret >= 2147483647)
		return (-1);
	if (is_of && ret < 0)
		return (0);
	return ((int)ret);
}

char			*pf_utils_itoa(long long num, const char * base, int bs, t_format *st)
{
	int		i;
	int		len;
	int		sign;
	char	*ret;

	len = pf_max(pf_utils_numlen(num, bs), st->pre);
	if (!(ret = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	sign = 1;
	if(num < 0)
		ret[(sign = 0)] = '-';
	while (++i < len + sign)
	{
		ret[len - i] = base[pf_utils_abs(num % bs)];
		num /= bs;
	}
	ret[len] = '\0';
	return (ret);
}
