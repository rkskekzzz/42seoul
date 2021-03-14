/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 10:31:49 by suhshin           #+#    #+#             */
/*   Updated: 2020/12/31 16:17:00 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int ch, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
	{
		*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		if (*((unsigned char *)src + i) == (unsigned char)ch)
			return (dest + i + 1);
	}
	return (NULL);
}
