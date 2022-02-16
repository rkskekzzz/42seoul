#ifndef ENTITIES_H
# define ENTITIES_H

# include <pthread.h>

typedef struct s_data
{
	int				value;
	pthread_mutex_t	lock;
}	t_data;

int		init_data(t_data *data);
int		sdata(t_data *data, int new_value);
int		gdata(t_data *data);

#endif
