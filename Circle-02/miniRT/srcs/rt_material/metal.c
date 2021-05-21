#include "minirt.h"

t_material create_metal(t_vec color, double fuzz)
{
	t_material mat;

	mat.color = vec_divn(color, 255);
	mat.scatter = scatter_metal;
	mat.fuzz = 1;
	if (fuzz < 1)
		mat.fuzz = fuzz;
	return (mat);
}

int scatter_metal(t_material *this, t_ray *ray_in, t_hit_record *rec, t_ray *ray_out)
{
	t_vec ray_in_dir_unit;
	t_vec target;

	ray_in_dir_unit = vec_unit_(&ray_in->dir);
	target = reflect_(&ray_in_dir_unit, &rec->n); // or random_unit_vector + near_zero
	target = vec_cal((t_vec[2]){target, random_in_unit_sphere()}, (double[2]){1, this->fuzz}, 2);
	ray_out->origin = rec->p; // random value에 의한 정점좌표를 새로 지정
	ray_out->dir = target;
	return (vec_dot_(&target, &rec->n) > 0);
}
