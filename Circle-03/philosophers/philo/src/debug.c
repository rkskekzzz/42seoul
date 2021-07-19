#include "philo.h"

void	print_condition(t_condition *cond)
{
	printf("num_of_philo : %d\n", cond->num_of_philo);
	printf("time_to_die : %d\n", cond->time_to_die);
	printf("time_to_eat : %d\n", cond->time_to_eat);
	printf("time_to_sleep : %d\n", cond->time_to_sleep);
	printf("num_of_philo_must_eat : %d\n", cond->num_of_philo_must_eat);
}
