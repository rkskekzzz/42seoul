#ifndef ENTITIES_H
# define ENTITIES_H

# include <pthread.h>

typedef struct s_data
{
	long long				value;
	pthread_mutex_t	lock;
}	t_data;

int		init_data(t_data *data);
int		sdata(t_data *data, long long new_value);
long long		gdata(t_data *data);

#endif
