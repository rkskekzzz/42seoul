#include "philo.h"

void	init_res(t_resource *res, t_condition *cond)
{
	int		idx;

	idx = -1;
	res->cond = cond;
	pthread_mutex_init(&res->table, NULL);
	res->fork = malloc(sizeof(pthread_mutex_t));
	if (!res->fork)
		exit(12);
	while (++idx < cond->num_of_philo)
	{
		pthread_mutex_init(res->fork, NULL);
	}
}

void	eat(t_philosopher *philo)
{
	printf("philo %d is eat\n", philo->idx);
	usleep(philo->res->cond->time_to_eat);
}

void	*routine(void *data)
{
	t_philosopher		*philo;

	philo = (t_philosopher *)data;
	printf("why??\n");
	pthread_mutex_lock(&philo->res->table);
	printf("ㅜㅜ\n");
	pthread_mutex_lock(&philo->res->fork[philo->idx]);
	pthread_mutex_lock(&philo->res->fork[(philo->idx + 1) % philo->res->cond->num_of_philo]);
	eat(philo);
	pthread_mutex_unlock(&philo->res->fork[(philo->idx + 1) % 5]);
	pthread_mutex_unlock(&philo->res->fork[philo->idx]);
	pthread_mutex_unlock(&philo->res->table);
	return (NULL);
}

void	philo(t_condition *cond)
{
	t_resource		res;
	t_philosopher	*philo;
	int				idx;

	init_res(&res, cond);
	idx = -1;
	philo = malloc(sizeof(t_philosopher) * cond->num_of_philo);
	while (++idx < cond->num_of_philo)
	{
		philo->idx = idx;
		philo->res = &res;
		pthread_create(&philo->philo, NULL, routine, (void *)&philo);
		pthread_join(philo->philo, NULL);
	}
	free(philo);
}
