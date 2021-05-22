/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:39:08 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/22 17:50:51 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	create_plane(t_pnt c, t_vec n)
{
	t_object obj;

	vec_print("plane c", &c);
	vec_print("plane n", &n);
	obj.plane.c = c;
	obj.plane.n = n;
	return (obj);
}

static int	get_plane_t(t_plane *pl, t_ray *ray,
		double minmax[2], double *t)
{
	double	d;

	d = vec_dot_(&ray->dir, &pl->n);
	if (ft_abs(d) < EPSILON)
		return (ERROR);
	*t = vec_dot(vec_cal((t_vec[2]){pl->c, ray->origin},
				(double[2]){1, -1}, 2), pl->n) / d;
	if (*t < minmax[0] || minmax[1] < *t)
		return (ERROR);
	return (OK);
}

int			hit_plane(t_world *this, t_ray *ray,
		double minmax[2], t_hit_record *rec)
{
	if (!get_plane_t(&this->obj.plane, ray, minmax, &rec->t))
		return (ERROR);
	rec->p = ray_at(ray, rec->t);
	rec->n = this->obj.plane.n;
	set_rec(this, ray, rec);
	return (OK);
}
