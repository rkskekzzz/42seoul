/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:19:24 by suhshin           #+#    #+#             */
/*   Updated: 2022/02/18 15:19:25 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "type.h"

void	_usleep(long long stime, int ptime)
{
	while (1)
	{
		if (timestamp() - stime >= ptime)
			break ;
		usleep(200);
	}
}

void	pick(t_philosopher *philo)
{
	if (philo->idx % 2 == 0)
	{
		pthread_mutex_lock(&philo->res->forks[philo->fork_idx[LEFT]].lock);
		pthread_mutex_lock(&philo->res->forks[philo->fork_idx[RIGHT]].lock);
	}
	else
	{
		pthread_mutex_lock(&philo->res->forks[philo->fork_idx[RIGHT]].lock);
		pthread_mutex_lock(&philo->res->forks[philo->fork_idx[LEFT]].lock);
	}	
	print(philo, PICK);
	print(philo, PICK);
}

void	eat(t_philosopher *philo)
{
	print(philo, EAT);
	sdata(&philo->die_time, timestamp() + philo->cond->time_to_die);
	sdata(&philo->eat_count, gdata(&philo->eat_count) + 1);
	_usleep(timestamp(), philo->cond->time_to_eat);
	pthread_mutex_unlock(&philo->res->forks[philo->fork_idx[LEFT]].lock);
	pthread_mutex_unlock(&philo->res->forks[philo->fork_idx[RIGHT]].lock);
}

void	nap(t_philosopher *philo)
{
	print(philo, SLEEP);
	_usleep(timestamp(), philo->cond->time_to_sleep);
}

void	think(t_philosopher *philo)
{
	print(philo, THINK);
	usleep(200);
}
