#include "philo.h"

void init_res(t_resource *res, t_condition *cond)
{
	int idx;

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

void eat(t_philosopher *philo)
{
	printf("philo %d is eat(%d, %d)\n",
		   philo->idx,
		   philo->idx,
		   (philo->idx + 1) % philo->res->cond->num_of_philo);
	usleep(philo->res->cond->time_to_eat);
}

void *routine(void *data)
{
	t_philosopher *philo;

	philo = (t_philosopher *)data;
	pthread_mutex_lock(&philo->res->table);
	pthread_mutex_lock(&philo->res->frk[philo->idx]);
	pthread_mutex_lock(&philo->res->fork[(philo->idx + 1) % philo->res->cond->num_of_philo]);
	eat(philo);
	pthread_mutex_unlock(&philo->res->fork[(philo->idx + 1) % philo->res->cond->num_of_philo]);
	pthread_mutex_unlock(&philo->res->fork[philo->idx]);
	pthread_mutex_unlock(&philo->res->table);
	return (NULL);
}

void philo(t_condition *cond)
{
	t_resource res;
	t_philosopher *philo;
	int idx;

	init_res(&res, cond);
	idx = -1;
	philo = malloc(sizeof(t_philosopher) * cond->num_of_philo);
	while (++idx < cond->num_of_philo)
	{
		philo[idx].idx = idx;
		philo[idx].res = &res;
		pthread_create(&philo->philo, NULL, routine, (void *)&philo[idx]);
		pthread_join(philo->philo, NULL);
	}
	free(philo);
}

// pthread_t		thread;
// int				idx;
// int				fork_idx;
// t_data			eat_count;
// t_data			die_time;
// t_resource		*res;
// t_condition		*cond;

int init_philo(t_philosopher *philos, int idx)
{
}

int init_philos(t_resource *res, t_philosopher **philos, t_condition *cond)
{
	int idx;

	idx = -1;
	*philos = malloc(sizeof(t_philosopher) * cond->num_of_philo);
	if (!philos)
		return (FALSE);
	while (++idx < cond->num_of_philo)
	{
		init_philo(philos[idx], idx);
	}
	return (TRUE);
}

int init_res(t_resource *res, t_condition *cond)
{
	res->forks = malloc(sizeof(t_data) * cond->num_of_philo);
	if (!res->forks || pthread_mutex_init(&res->table_lock, 0) < 0)
		return (FALSE);
	res->start = get_time();
	init_data(&res->end);
	return (TRUE);
}

int init(t_resource *res, t_philosopher **philos, t_condition *cond)
{
	if (!init_res(res, cond) || !init_philos(res, philos, cond))
		return (FALSE);
	return (TRUE);
}
