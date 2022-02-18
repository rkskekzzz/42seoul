/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:20:08 by suhshin           #+#    #+#             */
/*   Updated: 2022/02/18 15:20:09 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"
#include "type.h"

long long	timestamp(void)
{
	struct timeval	tv;

	if (!gettimeofday(&tv, NULL))
		return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	return (FALSE);
}
