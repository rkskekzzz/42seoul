#include "minirt.h"

void ray_at(t_ray *ray, double t)
{
	ray = ray->orig + t * ray->dir;
}

t_vec ray_origin(int x, int y, int z)
{
	t_vec new_vec;

	new_vec = malloc(sizeof(t_vec) * 1);
	if (!new_vec)
		return (NULL);
	new_vec->x = x;
	new_vec->y = y;
	new_vec->z = z;
	return (new_vec);
}
