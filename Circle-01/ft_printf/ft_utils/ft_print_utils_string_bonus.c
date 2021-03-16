/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_string_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:26:30 by suhshin           #+#    #+#             */
/*   Updated: 2021/03/16 22:20:11 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	pf_utils_strlen(const char *str)
{
	size_t	i;

	i = -1;
	while (*(++i + str))
		;
	return (i);
}

char	*pf_utils_strdup(const char *src)
{
	char	*dest;
	size_t	len;

	len = pf_utils_strlen(src);
	if (!(dest = (char *)malloc(len + 1)))
		return (NULL);
	pf_utils_memcpy(dest, src, len);
	dest[len] = '\0';
	return ((char *)dest);
}

char	pf_utils_width_char(t_format *st)
{
	if (st->type != 'c' && st->type != 's' && st->type != '%')
		return (' ');
	if (st->zero && !st->minus)
		return ('0');
	return (' ');
}

void	pf_utils_print_rep(char c, int n)
{
	char	*tmp;

	if (n < 0)
		return ;
	tmp = malloc(n + 1);
	if (!tmp)
		return ;
	pf_utils_memset(tmp, c, n);
	tmp[n] = '\0';
	pf_utils_putstr(tmp, 1);
	free(tmp);
	tmp = 0;
}
