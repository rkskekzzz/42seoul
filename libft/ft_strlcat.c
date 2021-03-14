/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 10:18:25 by suhshin           #+#    #+#             */
/*   Updated: 2020/12/31 10:20:49 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*d_start;
	char	*s_start;
	size_t	p_length;
	size_t	s_length;

	d_start = dst;
	s_start = (char *)(src);
	while (dstsize && *dst)
	{
		++dst;
		--dstsize;
	}
	while (*src)
		++src;
	p_length = (size_t)(dst - d_start);
	s_length = (size_t)(src - s_start);
	if (!dstsize)
		return (p_length + s_length);
	while (*s_start && dstsize-- > 1)
		*dst++ = *s_start++;
	*dst = '\0';
	return (p_length + s_length);
}
