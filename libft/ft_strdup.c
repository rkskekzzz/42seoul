/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 11:27:34 by suhshin           #+#    #+#             */
/*   Updated: 2020/12/31 12:07:40 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	len;

	len = ft_strlen(src);
	if (!(dest = (char *)malloc(len + 1)))
		return (NULL);
	ft_strlcpy(dest, src, len + 1);
	return ((char *)dest);
}
