/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:55:15 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/22 17:55:53 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	create_square(t_pnt c, t_vec n, double side)
{
	t_object obj;

	vec_print("square c", &c);
	vec_print("square n", &n);
	obj.square.c = c;
	obj.square.n = n;
	obj.square.side = side;
	return (obj);
}

static int	square_t_check(t_square *sq, t_ray *ray,
		double minmax[2], double *t)
{
	double	d;

	d = vec_dot_(&ray->dir, &sq->n);
	if (ft_abs(d) < EPSILON)
		return (ERROR);
	*t = vec_dot(vec_cal((t_vec[2]){sq->c, ray->origin},
				(double[2]){1, -1}, 2), sq->n) / d;
	if (*t < minmax[0] || minmax[1] < *t)
		return (ERROR);
	return (OK);
}

static int	get_square_t(t_square *sq, t_ray *ray,
		double minmax[2], double *t)
{
	double	cos_theta;
	double	limit;
	t_vec	random_vector;
	t_vec	side_vecter;
	t_vec	cp;

	if (!square_t_check(sq, ray, minmax, t))
		return (ERROR);
	random_vector = vec(0, 1, 0);
	if (ft_abs(sq->n.y) == 1)
		random_vector = vec(1, 0, 0);
	side_vecter = vec_cross_(&sq->n, &random_vector);
	cp = vec_cal((t_vec[2]){ray_at(ray, *t), sq->c}, \
			(double[2]){1, -1}, 2);
	cos_theta = ft_abs(vec_dot_(&side_vecter, &cp) / \
				(vec_length_(&side_vecter) * vec_length_(&cp)));
	if (cos_theta < sqrt(2) / 2)
		cos_theta = cos(M_PI_2 - acos(cos_theta));
	limit = (sq->side / 2) / cos_theta;
	if (vec_length_squared_(&cp) > limit * limit)
		return (ERROR);
	return (OK);
}

int			hit_square(t_world *this, t_ray *ray,
		double minmax[2], t_hit_record *rec)
{
	if (!get_square_t(&this->obj.square, ray, minmax, &rec->t))
		return (ERROR);
	rec->p = ray_at(ray, rec->t);
	rec->n = this->obj.square.n;
	set_rec(this, ray, rec);
	return (OK);
}
