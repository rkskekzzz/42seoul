#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

# include <sys/time.h>
# include <time.h>

# define LEFT		0
# define RIGHT 		1

# include "library.h"

// 상태
typedef struct s_condition
{
	int			num_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_of_philo_must_eat;
}	t_condition;

typedef struct s_data
{
	int value;
	pthread_mutex_t lock;
} t_data;
// 공유하는 자원
typedef struct s_resource
{
	int				start;
	t_data			end;
	t_data			*forks;
	pthread_mutex_t	table_lock;
}	t_resource;

// 개별 자원
typedef struct s_philosopher
{
	pthread_t		thread;
	int				idx;
	int				fork_idx;
	t_data			eat_count;
	t_data			die_time;
	t_resource		*res;
	t_condition		*cond;
}	t_philosopher;

typedef struct s_monitor
{
	t_philosopher	*philo;
	t_resource		*res;
	// t_condition		*cond;
}	t_monitor;

void	parsing(char **argv);
void	print_condition(t_condition *cond);
void	philo(t_condition *cond);

#endif
