/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 12:07:52 by suhshin           #+#    #+#             */
/*   Updated: 2020/12/31 12:07:54 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *set, size_t n)
{
	size_t	len;

	len = ft_strlen(set);
	if (!*set)
		return ((char *)s1);
	while (*s1 && n-- >= len)
	{
		if (*s1 == *set && !ft_memcmp(s1, set, len))
			return ((char *)s1);
		++s1;
	}
	return (NULL);
}
