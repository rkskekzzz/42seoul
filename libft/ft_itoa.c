/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 14:47:52 by suhshin           #+#    #+#             */
/*   Updated: 2021/01/02 09:12:55 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

static size_t	ft_intlen(int n)
{
	size_t	len;

	len = n < 0 ? 1 : 0;
	while (1)
	{
		++len;
		if (!(n / 10))
			break ;
		n /= 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int		sign;
	int		i;
	int		cnt;
	char	*buf;

	sign = n < 0 ? 1 : 0;
	i = -1;
	cnt = (int)ft_intlen(n);
	if (!(buf = (char *)malloc(cnt + 1)))
		return (NULL);
	if (sign)
		buf[++i] = '-';
	while (++i < cnt)
	{
		buf[cnt - (!sign) - i] = "0123456789"[ft_abs(n % 10)];
		n /= 10;
	}
	buf[cnt] = '\0';
	return (buf);
}
