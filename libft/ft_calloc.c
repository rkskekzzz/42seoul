/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 09:52:04 by suhshin           #+#    #+#             */
/*   Updated: 2020/12/31 12:14:06 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t cnt, size_t n)
{
	void	*ptr;

	if (!(ptr = (void *)malloc(n * cnt)))
		return (NULL);
	ft_bzero(ptr, n * cnt);
	return (ptr);
}
