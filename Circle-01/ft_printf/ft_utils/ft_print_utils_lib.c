/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_lib.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:26:30 by suhshin           #+#    #+#             */
/*   Updated: 2021/03/10 15:28:05 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*pf_utils_memset(void *dest, int value, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
		*((char *)dest + i) = value;
	return (dest);
}

void	pf_utils_putstr(char *s, int fd)
{
	int	len;

	if (!s)
		return ;
	len = pf_utils_strlen(s);
	write(fd, s, len);
}

void	pf_utils_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	*pf_utils_memcpy(void *dest, const void *src, size_t size)
{
	size_t	i;

	i = -1;
	if (dest != src && size)
		while (++i < size)
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
	return (dest);
}
