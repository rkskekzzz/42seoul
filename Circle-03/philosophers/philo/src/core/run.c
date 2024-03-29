/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:19:20 by suhshin           #+#    #+#             */
/*   Updated: 2022/02/18 15:19:21 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "type.h"

void	print(t_philosopher *philo, int type)
{
	pthread_mutex_lock(&philo->res->table_lock);
	if (!gdata(&philo->res->end))
	{
		printf("%lld %d %s\n", timestamp() - philo->res->start, \
				philo->idx + 1, message(type));
	}
	pthread_mutex_unlock(&philo->res->table_lock);
}

void	*routine(void *data)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)data;
	if (philo->idx % 2 == 0)
		usleep(200);
	while (1)
	{
		if (gdata(&philo->res->end))
			break ;
		if (philo->fork_idx[LEFT] == philo->fork_idx[RIGHT])
			continue ;
		pick(philo);
		eat(philo);
		nap(philo);
		think(philo);
	}
	return (NULL);
}

int	run(t_condition *cond, t_philosopher *philos)
{
	int	idx;

	idx = -1;
	while (++idx < cond->num_of_philo)
	{
		if (pthread_create(&philos[idx].thread, \
				NULL, \
				routine, \
				(void *)(&philos[idx])) != 0)
			return (FALSE);
	}
	return (TRUE);
}
