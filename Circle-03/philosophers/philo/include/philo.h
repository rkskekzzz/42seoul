/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:18:39 by suhshin           #+#    #+#             */
/*   Updated: 2022/02/18 15:18:40 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "entities.h"
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
	long long		start;
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
	long long				type;
}	t_end;

void	print(t_philosopher *philo, int type);
void	pick(t_philosopher *philo);
void	eat(t_philosopher *philo);
void	nap(t_philosopher *philo);
void	think(t_philosopher *philo);
int		run(t_condition *cond, t_philosopher *philos);
int		monitor(t_condition *cond, t_resource *res, t_philosopher *philos);
int		destroy(t_condition *cond, t_resource *res, t_philosopher *philos);
int		init(t_condition *cond, t_resource *res, t_philosopher **philos);

#endif
