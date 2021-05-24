/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:07:51 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/24 22:18:59 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize)
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

static size_t	ft_check_size(char const *s, char *delim)
{
	size_t	cnt;
	int		i;

	cnt = 0;
	i = -1;
	if (!*s)
		return (0);
	while (*(++i + s + 1))
		if (!ft_strchr(delim, *(i + s)) && ft_strchr(delim, *(i + s + 1)))
			++cnt;
	return (!ft_strchr(delim, *(s + i)) ? cnt + 1 : cnt);
}

char			**ft_free_split(char **s, int i)
{
	if (s == NULL)
		return (NULL);
	while (--i >= 0 && *(s + i))
	{
		free(*(s + i));
		*(s + i) = NULL;
	}
	free(s);
	s = NULL;
	return (NULL);
}

char			*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*dest;

	if (!s || !(dest = (char *)malloc(len + 1)))
		return (NULL);
	if ((int)start >= ft_strlen(s) ||
			!(ft_strlcpy(dest, s + start, len + 1)))
		dest[0] = '\0';
	return (dest);
}

char			**ft_split(char const *s, char *delim)
{
	char	**ret;
	char	*from;
	int		i;

	if (!s ||
		!(ret = malloc(sizeof(char *) * (ft_check_size(s, delim) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (!ft_strchr(delim, *s))
		{
			from = (char *)s;
			while (*s && !ft_strchr(delim, *s))
				++s;
			if (!(ret[i++] = ft_substr(from, 0, (s - from))))
				return (ft_free_split(ret, i));
		}
		else
			++s;
	}
	ret[i] = NULL;
	return (ret);
}
