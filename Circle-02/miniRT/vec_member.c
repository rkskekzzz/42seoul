#include "minirt.h"

void vec_print(t_vec *vec)
{
	printf("[%f, %f, %f]", vec->x, vec->y, vec->z);
}

// double vec_return(t_vec *vec, char ch)
// {
// 	if (ch = 'x')
// 		return (vec->x);
// 	else if (ch = 'y')
// 		return (vec->y);
// 	else if (ch = 'z')
// 		return (vec->z);
// 	return (0);
// }

void vec_addnum(t_vec *vec, double num)
{
	vec->x += num;
	vec->y += num;
	vec->z += num;
}

void vec_addvec(t_vec *vec, t_vec *add)
{
	vec->x += add->x;
	vec->y += add->y;
	vec->z += add->z;
}

void vec_subvec(t_vec *vec, t_vec *add)
{
	vec->x -= add->x;
	vec->y -= add->y;
	vec->z -= add->z;
}

void vec_mulnum(t_vec *vec, double num)
{
	vec->x *= num;
	vec->y *= num;
	vec->z *= num;
}

void vec_mulvec(t_vec *vec, t_vec *add)
{
	vec->x *= add->x;
	vec->y *= add->y;
	vec->z *= add->z;
}

void vec_divnum(t_vec *vec, double num)
{
	vec->x /= num;
	vec->y /= num;
	vec->z /= num;
}

void vec_cross(t_vec *vec, t_vec *add)
{
	vec->x = vec->y * add->z + vec->z * add->y;
	vec->y = vec->z * add->x + vec->x * add->z;
	vec->z = vec->x * add->y + vec->y * add->x;
}

double vec_dot(t_vec *vec, t_vec *add)
{
	return (vec->x * add->x + vec->y * add->y + vec->z * add->z);
}




double vec_length_squared(t_vec *vec)
{
	return (vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
}

double vec_length(t_vec *vec)
{
	double len;

	len = vec_length_squared(vec);
	len = sqrt(len);
	return (len);
}

t_vec *vec_unit_vector(t_vec *vec)
{
	double len;
	t_vec *new_vec;

	new_vec = malloc(sizeof(t_vec) * 1);
	if (!new_vec)
		return (NULL);
	len = vec_length(vec);
	new_vec->x = vec->x / len;
	new_vec->y = vec->y / len;
	new_vec->z = vec->z / len;
	return (new_vec);
}


void vec_oppo(t_vec *vec)
{
	vec->x = -vec->x;
	vec->y = -vec->y;
	vec->z = -vec->z;
}

t_vec *vec_alloc(double x, double y, double z)
{
	t_vec *new_vec;

	new_vec = malloc(sizeof(t_vec) * 1);
	if (!new_vec)
		return (NULL);
	new_vec->x = x;
	new_vec->y = y;
	new_vec->z = z;
	return (new_vec);
}

t_vec *ray_at(t_ray *ray, double t)
{
	return vec_alloc(ray->origin->x + ray->dir->x * t
					,ray->origin->y + ray->dir->y * t
					,ray->origin->z + ray->dir->z * t);
}
