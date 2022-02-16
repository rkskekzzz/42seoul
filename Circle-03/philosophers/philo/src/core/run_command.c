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
		usleep(100);
		pthread_mutex_unlock(&philo->res->forks[philo->fork_idx[LEFT]].lock);
		pthread_mutex_unlock(&philo->res->forks[philo->fork_idx[RIGHT]].lock);
	}
	pthread_mutex_unlock(&philo->res->forks[philo->fork_idx[LEFT]].lock);
	pthread_mutex_unlock(&philo->res->forks[philo->fork_idx[RIGHT]].lock);
	print(philo, PICK);
	print(philo, PICK);
}

void	eat(t_philosopher *philo)
{
	pick(philo);
	sdata(&philo->die_time, timestamp() + philo->cond->time_to_die); // 죽을 시간 연장
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
