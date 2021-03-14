/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_cal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:26:30 by suhshin           #+#    #+#             */
/*   Updated: 2021/03/10 15:27:52 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int pf_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int pf_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int pf_utils_numlen(long long num, int base)
{
	size_t	ret;

	ret = 1;
	if (num < 0)
	{
		++ret;
		num *= -1;
	}
	while ((num /= base) > 0)
		++ret;
	return (ret);
}

long long	pf_utils_abs(long long num)
{
	if (num < 0)
		return (-num);
	return (num);
}
