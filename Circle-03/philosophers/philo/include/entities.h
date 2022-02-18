/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:18:27 by suhshin           #+#    #+#             */
/*   Updated: 2022/02/18 15:18:30 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITIES_H
# define ENTITIES_H

# include <pthread.h>

typedef struct s_data
{
	long long				value;
	pthread_mutex_t			lock;
}	t_data;

int			init_data(t_data *data);
int			sdata(t_data *data, long long new_value);
long long	gdata(t_data *data);

#endif
