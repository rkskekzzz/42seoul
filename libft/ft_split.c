/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:05:17 by suhshin           #+#    #+#             */
/*   Updated: 2021/01/02 14:20:50 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check_size(char const *s, char c)
{
	size_t	cnt;
	int		i;

	cnt = 0;
	i = -1;
	if (!*s)
		return (0);
	while (*(++i + s + 1))
		if (*(i + s) != c && *(i + s + 1) == c)
			++cnt;
	return (*(s + i) != c ? cnt + 1 : cnt);
}

static char		**ft_free_split(char **s, int i)
{
	while (--i >= 0 && *(s + i))
	{
		free(*(s + i));
		*(s + i) = NULL;
	}
	free(s);
	s = NULL;
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**ret;
	char	*from;
	int		i;

	if (!s ||
		!(ret = (char **)malloc(sizeof(char *) * (ft_check_size(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			from = (char *)s;
			while (*s && *s != c)
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
