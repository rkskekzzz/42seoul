/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 10:37:55 by suhshin           #+#    #+#             */
/*   Updated: 2020/12/31 12:05:55 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *dest, int ch, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
		if (*((unsigned char *)dest + i) == (unsigned char)ch)
			return ((void *)dest + i);
	return (NULL);
}
