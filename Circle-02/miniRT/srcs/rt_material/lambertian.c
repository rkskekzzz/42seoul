#include "minirt.h"

t_material create_lambertian(t_vec color)
{
	t_material mat;

	mat.color = vec_divn(color, 255);
	mat.scatter = scatter_lambertian;
	return (mat);
}

int scatter_lambertian(t_material *this, t_ray *ray_in, t_hit_record *rec, t_ray *ray_out)
{
	t_vec target;

	target = random_in_hemisphere(&rec->n); // or random_unit_vector + near_zero
	ray_out->origin = rec->p; // random value에 의한 정점좌표를 새로 지정
	ray_out->dir = target;
	return (1);
}
