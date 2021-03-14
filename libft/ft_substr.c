/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 12:06:11 by suhshin           #+#    #+#             */
/*   Updated: 2020/12/31 12:18:56 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	if (!s || !(dest = (char *)malloc(len + 1)))
		return (NULL);
	if ((size_t)start >= ft_strlen(s) ||
			!(ft_strlcpy(dest, s + start, len + 1)))
		dest[0] = '\0';
	return (dest);
}
