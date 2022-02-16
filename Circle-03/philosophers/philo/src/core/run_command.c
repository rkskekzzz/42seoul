#include "philo.h"
#include "type.h"

void	pick(t_philosopher *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->res->forks[philo->fork_idx[LEFT]].lock);
		pthread_mutex_lock(&philo->res->forks[philo->fork_idx[RIGHT]].lock);
		if (philo->res->forks[philo->fork_idx[LEFT]].value == 0 && \
			philo->res->forks[philo->fork_idx[RIGHT]].value == 0)
		{
			philo->res->forks[philo->fork_idx[LEFT]].value = 1;
			philo->res->forks[philo->fork_idx[RIGHT]].value = 1;
			break ;
		}
		pthread_mutex_unlock(&philo->res->forks[philo->fork_idx[LEFT]].lock);
		pthread_mutex_unlock(&philo->res->forks[philo->fork_idx[RIGHT]].lock);
		usleep(100);
	}
	pthread_mutex_unlock(&philo->res->forks[philo->fork_idx[LEFT]].lock);
	pthread_mutex_unlock(&philo->res->forks[philo->fork_idx[RIGHT]].lock);
	print(philo, PICK);
	print(philo, PICK);
}

void	eat(t_philosopher *philo)
{
	print(philo, EAT);
	sdata(&philo->die_time, timestamp() + philo->cond->time_to_die);
	sdata(&philo->eat_count, gdata(&philo->eat_count) + 1);
	usleep(philo->cond->time_to_eat);
	sdata(&philo->res->forks[philo->fork_idx[LEFT]], 0);
	sdata(&philo->res->forks[philo->fork_idx[RIGHT]], 0);
}

void	nap(t_philosopher *philo)
{
	print(philo, SLEEP);
	usleep(philo->cond->time_to_sleep);
}

void	think(t_philosopher *philo)
{
	print(philo, THINK);
}
