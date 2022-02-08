#include "philo.h"
#include "type.h"

int	init_philo (
	int idx,
	t_philosopher *philo,
	t_resource *res,
	t_condition *cond
) {
	philo->idx = idx;
	philo->fork_idx[LEFT] = idx;
	philo->fork_idx[RIGHT] = (idx + 1) % cond->num_of_philo;
	philo->res = res;
	philo->cond = cond;
	if (init_data(&philo->eat_count) || \
		init_data(&philo->die_time) || \
		sdata(&philo->die_time, res->start + cond->time_to_die))
		return (FALSE);
	return (TRUE);
}

int	init_philos(t_resource *res, t_philosopher **philos, t_condition *cond)
{
	int	idx;

	idx = -1;
	*philos = malloc(sizeof(t_philosopher) * cond->num_of_philo);
	if (!philos)
		return (FALSE);
	while (++idx < cond->num_of_philo)
	{
		if (init_philo(idx, &(*philos)[idx], res, cond))
			return (FALSE);
	}
	return (TRUE);
}

int	init_forks(t_resource *res, int count)
{
	int	idx;

	idx = -1;
	while (++idx < count)
	{
		if (init_data(&res->forks[idx]))
			return (FALSE);
	}
	return (TRUE);
}

int	init_res(t_resource *res, t_condition *cond)
{
	res->forks = malloc(sizeof(t_data) * cond->num_of_philo);
	res->start = timestamp();


	if (!res->forks || \
		res->start < 0 || \
		pthread_mutex_init(&res->table_lock, 0) || \
		init_data(&res->end))
		return (FALSE);
	return (TRUE);
}

int	init(t_resource *res, t_philosopher **philos, t_condition *cond)
{
	if (init_res(res, cond) || \
		init_forks(res, cond->num_of_philo) || \
		init_philos(res, philos, cond))
		return (FALSE);
	return (TRUE);
}
