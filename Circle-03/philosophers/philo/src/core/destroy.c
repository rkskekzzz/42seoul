/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:19:03 by suhshin           #+#    #+#             */
/*   Updated: 2022/02/18 15:19:04 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "type.h"

int	destroy(
t_condition *cond, \
t_resource *res, \
t_philosopher *philos
) {
	int	idx;

	pthread_mutex_destroy(&res->table_lock);
	pthread_mutex_destroy(&res->end.lock);
	idx = -1;
	while (++idx < cond->num_of_philo)
	{
		pthread_mutex_destroy(&res->forks[idx].lock);
		pthread_mutex_destroy(&philos[idx].eat_count.lock);
		pthread_mutex_destroy(&philos[idx].die_time.lock);
	}
	free(philos);
	free(res->forks);
	return (TRUE);
}
