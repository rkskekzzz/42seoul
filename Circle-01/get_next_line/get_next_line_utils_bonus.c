/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:03:52 by suhshin           #+#    #+#             */
/*   Updated: 2021/02/12 21:59:54 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	gnl_free(char **str)
{
	free(*str);
	*str = NULL;
}

size_t	gnl_strlen(char *str)
{
	size_t	i;

	i = -1;
	while (*(++i + str))
		;
	return (i);
}

size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	if (dstsize)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	while (src[i])
		++i;
	return (i);
}

char	*gnl_strdup(char *src)
{
	char	*dest;
	size_t	len;

	len = gnl_strlen(src);
	if (!(dest = (char *)malloc(len + 1)))
		return (NULL);
	gnl_strlcpy(dest, src, len + 1);
	return ((char *)dest);
}
