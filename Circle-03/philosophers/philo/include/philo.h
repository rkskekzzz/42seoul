#ifndef PHILO_H
# define PHILO_H

# include "entities.h"
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

/**
 * 공유자원 구조체
 * forks : 포크 배열 ( { value, mutex} )
 * start : 시뮬레이션 시작시간
 * end : 시뮬레이션 종료 확인 값 ( { value, mutex} )
 * table_lock : 출력을 위한 뮤텍스
 */
typedef struct s_resource
{
	int				start;
	t_data			end;
	t_data			*forks;
	pthread_mutex_t	table_lock;
}	t_resource;

typedef struct s_philosopher
{
	pthread_t		thread;
	int				idx;
	int				fork_idx[2];
	t_data			eat_count;
	t_data			die_time;
	t_resource		*res;
	t_condition		*cond;
}	t_philosopher;

typedef struct s_monitor
{
	t_philosopher	*philos;
	t_resource		*res;
	t_condition		*cond;
}	t_monitor;

typedef struct s_end
{
	int				type;
}	t_end;

t_end	*end_state(void);
void	print(t_philosopher *philo, int type);
void	pick(t_philosopher *philo);
void	eat(t_philosopher *philo);
void	nap(t_philosopher *philo);
void	think(t_philosopher *philo);
int		run(t_condition *cond, t_philosopher *philos);
int		monitor(t_condition *cond, t_resource *res, t_philosopher *philos);
int		destroy();
int		init(t_condition *cond, t_resource *res, t_philosopher **philos);

#endif
