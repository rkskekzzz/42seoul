/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:19:45 by suhshin           #+#    #+#             */
/*   Updated: 2022/02/18 15:19:46 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"
#include "type.h"
#include <stdio.h>

int	init_data(t_data *data)
{
	data->value = 0;
	if (!pthread_mutex_init(&data->lock, 0))
		return (TRUE);
	return (FALSE);
}

int	sdata(t_data *data, long long new_value)
{
	pthread_mutex_lock(&data->lock);
	data->value = new_value;
	pthread_mutex_unlock(&data->lock);
	return (TRUE);
}

long long	gdata(t_data *data)
{
	long long	value;

	pthread_mutex_lock(&data->lock);
	value = data->value;
	pthread_mutex_unlock(&data->lock);
	return (value);
}
