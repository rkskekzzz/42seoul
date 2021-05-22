/*
static t_vec	random_in_unit_disk(double dist_to_focus)
{
	t_vec	out;

	while (1)
	{
		out = vec(rand_num(1, -1, 1),rand_num(1, -1, 1),0);
		if (vec_length_squared_(&out) >= 1)
			continue ;
		return (vec_cal(&out, &dist_to_focus, 1));
	}
}

static t_clr ray_color_scatter(t_world *world, t_ray *ray, int depth)
{
	t_hit_record	rec;
	t_ray			new_ray;
	double			val_for_sky;
	t_vec			ray_from_cam;

	if (depth <= 0)
		return ((t_vec){0, 0, 0});
	if (hit_world(world, ray, (double [2]){EPSILON, INFINITY}, &rec))
	{
		if (rec.material->scatter(rec.material, ray, &rec, &new_ray))
			return (vec_mul(rec.material->color, \
					ray_color_scatter(world, &new_ray, depth - 1)));
		return (vec(0, 0, 0));
	}
	ray_from_cam = vec_oppo(vec_unit_(&ray->dir));
	val_for_sky = 0.5 - 0.5 * ray_from_cam.y;
	return (vec((1 - 0.5 * val_for_sky), (1 - 0.3 * val_for_sky), 1));
}
*/