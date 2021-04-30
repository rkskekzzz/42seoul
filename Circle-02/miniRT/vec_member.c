#include "minirt.h"

void vec_print(t_vec *vec)
{
	printf("[%.2f, %.2f, %.2f]", vec->x, vec->y, vec->z);
}

void vec_cross(t_vec *out, t_vec *v1, t_vec *v2)
{
	out->x = v1->y * v2->z + v1->z * v2->y;
	out->y = v1->z * v2->x + v1->x * v2->z;
	out->z = v1->x * v2->y + v1->y * v2->x;
}

double vec_dot(t_vec *v1, t_vec *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
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

void vec(t_vec *out, double x, double y, double z)
{
	out->x = x;
	out->y = y;
	out->z = z;
}

void vec_unit(t_vec *out, t_vec *v)
{
	double len;

	len = vec_length(v);
	vec(out, v->x / len
			,v->y / len
			,v->z / len);
}

void ray_at(t_vec *out, t_ray *ray, double t)
{
	vec(out, ray->origin.x + ray->dir.x * t
			,ray->origin.y + ray->dir.y * t
			,ray->origin.z + ray->dir.z * t);
}


void vec_cal(t_vec *out, t_vec *v, double *a, int n)
{
	vec(out, 0, 0, 0);
	while (n--)
	{
		out->x += v[n].x * a[n];
		out->y += v[n].y * a[n];
		out->z += v[n].z * a[n];
	}
}
