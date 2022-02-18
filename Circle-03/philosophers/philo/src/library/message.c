/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:20:02 by suhshin           #+#    #+#             */
/*   Updated: 2022/02/18 15:20:12 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

char	*message(int type)
{
	if (type == 0)
		return ("has taken a fork");
	else if (type == 1)
		return ("is eating");
	else if (type == 2)
		return ("is sleeping");
	else if (type == 3)
		return ("is thinking");
	else
		return ("died");
}
