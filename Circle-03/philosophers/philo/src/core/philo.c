#include "philo.h"

void	*test(void *data)
{
	t_resource	*res;
	int			i;

	i = -1;
	res = (t_resource *)data;
	printf("------ start test --------\n");
	while (++i < 1)
	{
		printf("??\n");
		pthread_mutex_lock(&res->fork[i]);
		usleep(res->cond->time_to_sleep);
		pthread_mutex_unlock(&res->fork[i]);
	}
	return (NULL);
}

void	init_res(t_resource **res, t_condition *cond)
{
	int		idx;

	idx = -1;
	(*res) = malloc(sizeof(t_resource) * cond->num_of_philo);
	if (!*res)
		exit(12);
	while (++idx < cond->num_of_philo)
	{
		pthread_mutex_init((*res)[idx].fork, NULL);
	}
}

void	init_philo(t_philo **philo, t_condition *cond, t_resource *res)
{
	(*philo) = malloc(sizeof(t_philo) * cond->num_of_philo);
	if (!*philo)
		exit(12);
}

void	philo(t_condition *cond)
{
	t_philo		*philo;
	t_resource	*res;

	init_res(&res, cond);
	init_philo(&philo, cond, res);
	while (++res->idx < cond->num_of_philo)
	{
		printf("here\n");
		init_philo();
		if (pthread_create(&thread[res->idx], NULL, test, (void *)&res) < 0)
		{
			perror("thread create error:");
			exit(0);
		}
		pthread_join(thread[res->idx], (void **)&status);
	}
	return ;
}
