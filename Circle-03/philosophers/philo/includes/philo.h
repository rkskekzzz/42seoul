#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

# include <sys/time.h>
# include <time.h>

# include "library.h"

# define TRUE 1
# define FALSE 0

typedef int	t_bool;

typedef struct s_condition
{
	int			num_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_of_philo_must_eat;
}				t_condition;

void	parsing(char **argv);
void	print_condition(t_condition *cond);

#endif
