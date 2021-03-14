/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 10:46:14 by suhshin           #+#    #+#             */
/*   Updated: 2020/12/31 16:18:33 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t	i;

	i = dest > src ? size + 1 : -1;
	if (dest != src && size)
	{
		if (dest > src)
			while (--i)
				((unsigned char *)dest)[i - 1] = ((unsigned char *)src)[i - 1];
		else
			while (++i < size)
				((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	}
	return (dest);
}
