/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:07:38 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/22 17:10:14 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_isspace(char c)
{
	return (c == 32);
}

int		ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int		ft_isnum(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		++i;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (ERROR);
		++i;
	}
	return (OK);
}
