#include "minirt.h"

t_vec vec_cross(t_vec v1, t_vec v2)
{
	t_vec out;

	out.x = v1.y * v2.z - v1.z * v2.y;
	out.y = v1.z * v2.x - v1.x * v2.z;
	out.z = v1.x * v2.y - v1.y * v2.x;
	return (out);
}

t_vec vec_cross_(t_vec *v1, t_vec *v2)
{
	t_vec out;

	out.x = v1->y * v2->z - v1->z * v2->y;
	out.y = v1->z * v2->x - v1->x * v2->z;
	out.z = v1->x * v2->y - v1->y * v2->x;
	return (out);
}

double vec_dot(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

double vec_dot_(t_vec *v1, t_vec *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}
