#include "philo.h"
#include "type.h"

void	print(t_philosopher *philo, int type)
{
	pthread_mutex_lock(&philo->res->table_lock);
	printf("%lld %d %s\n", timestamp() - philo->res->start, \
		philo->idx, message(type));
	pthread_mutex_unlock(&philo->res->table_lock);
}

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
		usleep(100);
		pthread_mutex_unlock(&philo->res->forks[philo->fork_idx[LEFT]].lock);
		pthread_mutex_unlock(&philo->res->forks[philo->fork_idx[RIGHT]].lock);
	}
	pthread_mutex_unlock(&philo->res->forks[philo->fork_idx[LEFT]].lock);
	pthread_mutex_unlock(&philo->res->forks[philo->fork_idx[RIGHT]].lock);
	print(philo, PICK);
	print(philo, PICK);
	sdata(&philo->die_time, philo->cond->time_to_die); // 죽을 시간 연장
	sdata(&philo->eat_count, gdata(&philo->eat_count) + 1); // 먹은 회수 증가
	print(philo, EAT); // 메세지 출력
	usleep(philo->cond->time_to_eat); // 먹는동안 잠자기
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

void	*routine(void *data)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)data;
	while (1)
	{
		pick(philo);
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
