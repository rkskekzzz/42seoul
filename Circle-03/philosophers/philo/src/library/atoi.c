/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:19:53 by suhshin           #+#    #+#             */
/*   Updated: 2022/02/18 15:19:54 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	ph_atoi(char *str)
{
	long long	answer;
	int			minus;
	int			i;

	i = 0;
	minus = 1;
	answer = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			answer = answer * 10 + str[i] - '0';
		else
			break ;
		i++;
	}
	return (minus * answer);
}
