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

void	init_thread(pthread_t **thread, t_condition *cond)
{
	*thread = malloc(sizeof(pthread_t) * cond->num_of_philo);
	if (!thread)
		exit(12);
}

void	init_resource(t_resource **res, t_condition *cond)
{
	int	i;

	i = -1;
	*res = malloc(sizeof(t_resource) * cond->num_of_philo);
	if (!res)
		exit(12);
	(*res)->idx = -1;
	(*res)->cond = cond;
	(*res)->fork = malloc(sizeof(pthread_t) * cond->num_of_philo);
	if (!(*res)->fork)
		exit(12);
	while (++i < cond->num_of_philo)
		pthread_mutex_init(&(*res)->fork[i], NULL);
}

void	init_philo(t_philo philo)
{

}

void	philo(t_condition *cond)
{
	pthread_t	*thread;
	t_resource	*res;
	t_philo		*philo;
	int			status;

	init_thread(&thread, cond);
	init_resource(&res, cond);
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
