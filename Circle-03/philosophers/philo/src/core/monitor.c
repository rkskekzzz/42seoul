/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:19:12 by suhshin           #+#    #+#             */
/*   Updated: 2022/02/18 15:19:13 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "type.h"
#include "library.h"

int	check_die(t_monitor	*monitor)
{
	int	idx;

	idx = -1;
	while (++idx < monitor->cond->num_of_philo)
	{
		if (gdata(&monitor->philos[idx].die_time) < timestamp())
		{
			print(&monitor->philos[idx], DIE);
			sdata(&monitor->res->end, 1);
			return (FALSE);
		}
	}
	return (TRUE);
}

int	check_full(t_monitor *monitor)
{
	int	idx;

	idx = -1;
	while (++idx < monitor->cond->num_of_philo)
	{
		if (gdata(&monitor->philos[idx].eat_count) < \
			monitor->cond->num_of_philo_must_eat)
			return (TRUE);
	}
	sdata(&monitor->res->end, 1);
	return (FALSE);
}

void	*monitor_routine(void *data)
{
	t_monitor	*monitor;

	monitor = (t_monitor *)data;
	while (1)
	{
		if (check_die(monitor))
			break ;
		if (monitor->cond->num_of_philo_must_eat != -1 && \
			check_full(monitor))
			break ;
		usleep(200);
	}
	return (NULL);
}

int	monitor(t_condition *cond, t_resource *res, t_philosopher *philos)
{
	int			idx;
	pthread_t	monitor_thread;
	t_monitor	monitor;

	idx = -1;
	monitor.cond = cond;
	monitor.philos = philos;
	monitor.res = res;
	if (pthread_create(&monitor_thread, \
			NULL, \
			monitor_routine, \
			(void *)(&monitor)))
		return (FALSE);
	pthread_join(monitor_thread, 0);
	while (++idx < cond->num_of_philo)
		pthread_join(philos[idx].thread, 0);
	return (TRUE);
}
