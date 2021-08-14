#include "philo.h"

void	init_res(t_resource **res, t_condition *cond)
{
	int		idx;

	idx = -1;
	(*res) = malloc(sizeof(t_resource));
	if (!*res)
		exit(12);
	(*res)->cond = cond;
	(*res)->fork = malloc(sizeof(pthread_mutex_t));
	if (!(*res)->fork)
		exit(12);
	pthread_mutex_init((*res)->fork, NULL);
}

void	init_philosopher(t_philosopher **philo, t_condition *cond, t_resource *res)
{
	int	idx;

	(*philo) = malloc(sizeof(t_philosopher) * cond->num_of_philo);
	if (!*philo)
		exit(12);
	idx = -1;
	while (++idx < cond->num_of_philo)
	{
		(*philo)[idx].idx = idx;
		(*philo)[idx].res = res;
		(*philo)[idx].fork[LEFT] = &res->fork[0];
		(*philo)[idx].fork[RIGHT] = &res->fork[1];
	}
}

void	*monitoring(void *data)
{
	t_monitor	*monitor;
	int			i;

	i = -1;
	monitor = (t_monitor *)data;
	printf("------ start test --------\n");
	printf("%d\n", monitor->res->cond->num_of_philo);
	while (++i < monitor->res->cond->num_of_philo)
	{
		printf(" -> %d %d\n", i, monitor->philo[i].idx);
	}
	return (NULL);
}

void	init_monitor(t_monitor **monitor, t_philosopher *philo, t_resource *res)
{
	pthread_t	monitor_thread;

	(*monitor) = malloc(sizeof(t_monitor));
	if (!(*monitor))
		exit(12);
	(*monitor)->philo = philo;
	(*monitor)->res = res;
	if (pthread_create(&monitor_thread, NULL, monitoring, (void *)(*monitor)) < 0)
	{
		perror("thread create error:");
		exit(0);
	}
	pthread_join(monitor_thread, NULL);
}

void	philo(t_condition *cond)
{
	t_philosopher	*philo;
	t_monitor		*monitor;
	t_resource		*res;

	init_res(&res, cond);
	init_philosopher(&philo, cond, res);
	init_monitor(&monitor, philo, res);
	return ;
}
