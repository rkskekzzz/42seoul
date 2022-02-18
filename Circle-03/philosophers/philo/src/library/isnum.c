/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isnum.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:19:58 by suhshin           #+#    #+#             */
/*   Updated: 2022/02/18 15:20:56 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"
#include "type.h"

int	ph_isnum(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
	}
	return (TRUE);
}
