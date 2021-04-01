#include "minirt.h"

void ray_at(t_ray *ray, double t)
{
	ray = ray->orig + t * ray->dir;
}

t_vec ray_origin(t_vec *vec)
{
	t_vec new_vec;

	new_vec = malloc(sizeof(t_vec) * 1);
	if (!new_vec)
		return (NULL);

	return (new_vec);
}
