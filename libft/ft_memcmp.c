/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 10:41:31 by suhshin           #+#    #+#             */
/*   Updated: 2020/12/31 12:20:01 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
		if ((*((unsigned char *)s1 + i) != *((unsigned char *)s2 + i)))
			return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
	return (0);
}
