/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:51:13 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/22 17:52:04 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	create_sphere(t_vec c, double r)
{
	t_object	obj;

	vec_print("sphere", &c);
	obj.sphere.c = c;
	obj.sphere.r = r / 2;
	return (obj);
}

static int	get_sphere_t(t_sphere *sp, t_ray *ray,
		double minmax[2], double *t)
{
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	t_vec	oc;

	oc = vec_cal((t_vec[2]){ray->origin, sp->c}, (double[2]){1, -1}, 2);
	a = vec_length_squared_(&ray->dir);
	half_b = vec_dot_(&oc, &ray->dir);
	c = vec_length_squared_(&oc) - sp->r * sp->r;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (ERROR);
	*t = (-half_b - sqrt(discriminant)) / a;
	if (*t < minmax[0] || minmax[1] < *t)
	{
		*t = (-half_b + sqrt(discriminant)) / a;
		if (*t < minmax[0] || minmax[1] < *t)
			return (ERROR);
	}
	return (OK);
}

int			hit_sphere(t_world *this, t_ray *ray,
		double minmax[2], t_hit_record *rec)
{
	if (!get_sphere_t(&this->obj.sphere, ray, minmax, &rec->t))
		return (ERROR);
	rec->p = ray_at(ray, rec->t);
	rec->n = vec_cal((t_vec[2]){rec->p, this->obj.sphere.c}, \
			(double[2]){1 / this->obj.sphere.r, -1 / this->obj.sphere.r}, 2);
	set_rec(this, ray, rec);
	return (OK);
}
