#include "entities.h"
#include "type.h"
#include <stdio.h>

int	init_data(t_data *data)
{
	data->value = 0;
	if (!pthread_mutex_init(&data->lock, 0))
		return (TRUE);
	return (FALSE);
}

/**
 * @brief Set the data object
 *
 * @param data for which you want to assign a value
 * @param new_value to enter data
 * @return TRUE (0) / FALSE (-1)
 */
int	sdata(t_data *data, long long new_value)
{
	pthread_mutex_lock(&data->lock);
	data->value = new_value;
	pthread_mutex_unlock(&data->lock);
	return (TRUE);
}

long long	gdata(t_data *data)
{
	long long	value;

	pthread_mutex_lock(&data->lock);
	value = data->value;
	pthread_mutex_unlock(&data->lock);
	return (value);
}
