#include "philo.h"
#include "type.h"

t_end	*end_state(void)
{
	static t_end	end_state;

	return (&end_state);
}

void	print(t_philosopher *philo, int type)
{
	pthread_mutex_lock(&philo->res->table_lock);
	if (end_state()->type != DIE)
	{
		printf("%d %d %s\n", timestamp() - philo->res->start, \
				philo->idx + 1, message(type));
	}
	pthread_mutex_unlock(&philo->res->table_lock);
}

void	*routine(void *data)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)data;
	while (1)
	{
		if (gdata(&philo->res->end))
			break ;
		eat(philo);
		nap(philo);
		think(philo);
		usleep(200);
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
