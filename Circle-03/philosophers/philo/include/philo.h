#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

# include <sys/time.h>
# include <time.h>

# include "library.h"

typedef struct s_condition
{
	int			num_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_of_philo_must_eat;
}	t_condition;

typedef struct s_resource
{
	pthread_mutex_t	*fork;
}	t_resource;

typedef struct s_philo
{
	int				idx;
	pthread_t		philo;
	pthread_mutex_t	*fork[2];
	t_condition		*cond;
}	t_philo;

void	parsing(char **argv);
void	print_condition(t_condition *cond);
void	philo(t_condition *cond);

#endif
