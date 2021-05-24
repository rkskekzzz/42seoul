/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:52:20 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/24 22:17:37 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object		create_triangle(t_vec p1, t_vec p2, t_vec p3)
{
	t_object	obj;

	obj.triangle.p1 = p1;
	obj.triangle.p2 = p2;
	obj.triangle.p3 = p3;
	obj.triangle.e1 = vec_sub_(&p2, &p1);
	obj.triangle.e2 = vec_sub_(&p3, &p2);
	obj.triangle.e3 = vec_sub_(&p1, &p3);
	obj.triangle.n = vec_unit(vec_cross(obj.triangle.e1, \
										vec_oppo(obj.triangle.e3)));
	return (obj);
}

static int		triangle_t_check(t_triangle *tr, t_ray *ray,
		double minmax[2], double *t)
{
	double	d;

	d = vec_dot_(&ray->dir, &tr->n);
	if (ft_abs(d) < EPSILON)
		return (ERROR);
	*t = vec_dot(vec_cal((t_vec[2]){tr->p1, ray->origin},
				(double[2]){1, -1}, 2), tr->n) / d;
	if (*t < minmax[0] || minmax[1] < *t)
		return (ERROR);
	return (OK);
}

static int		get_triangle_t(t_triangle *tr, t_ray *ray,
		double minmax[2], double *t)
{
	t_vec	p;

	if (!triangle_t_check(tr, ray, minmax, t))
		return (ERROR);
	p = ray_at(ray, *t);
	if (vec_dot(tr->n, vec_cross(tr->e1, vec_sub(p, tr->p1))) < 0 || \
		vec_dot(tr->n, vec_cross(tr->e2, vec_sub(p, tr->p2))) < 0 || \
		vec_dot(tr->n, vec_cross(tr->e3, vec_sub(p, tr->p3))) < 0)
		return (ERROR);
	return (OK);
}

int				hit_triangle(t_world *this, t_ray *ray,
		double minmax[2], t_hit_record *rec)
{
	if (!get_triangle_t(&this->obj.triangle, ray, minmax, &rec->t))
		return (ERROR);
	rec->p = ray_at(ray, rec->t);
	rec->n = this->obj.triangle.n;
	set_rec(this, ray, rec);
	return (OK);
}
