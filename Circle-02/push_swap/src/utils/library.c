/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:28:21 by suhshin           #+#    #+#             */
/*   Updated: 2021/08/11 20:28:22 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ps_memset(void *dest, int value, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
		*((char *)dest + i) = value;
	return (dest);
}

int	ps_isnum_atoi(char *s)
{
	int			sign;
	long long	ret;

	sign = 1;
	ret = 0;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -1;
	while (*s >= '0' && *s <= '9')
	{
		ret = ret * 10 + (*s++ - '0');
		if (ret - 1 * (sign == -1) > INTMAX)
			exit(prt_error("Numsize Error!"));
	}
	if (*s != 0)
		exit(prt_error("Not Number Error!"));
	return ((int)ret * sign);
}

void	ps_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ps_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

char	*ps_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		++s;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
