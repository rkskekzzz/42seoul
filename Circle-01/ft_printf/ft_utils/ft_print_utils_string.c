/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:26:30 by suhshin           #+#    #+#             */
/*   Updated: 2021/03/10 15:28:11 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	pf_utils_strlen(const char *str)
{
	size_t	i;

	i = -1;
	while (*(++i + str))
		;
	return (i);
}

char	*pf_utils_strdup(const char *src)
{
	char	*dest;
	size_t	len;

	len = pf_utils_strlen(src);
	if (!(dest = (char *)malloc(len + 1)))
		return (NULL);
	pf_utils_memcpy(dest, src, len);
	dest[len] = '\0';
	return ((char *)dest);
}

