/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dielectric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:32:36 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/24 22:19:47 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_material		create_dielectric(double ir)
{
	t_material mat;

	mat.color = vec(1.0, 1.0, 1.0);
	mat.ir = ir;
	mat.scatter = scatter_dielectric;
	return (mat);
}

static t_vec	refract(t_vec *r_in, t_vec *n, double ir, double cos_theta)
{
	t_vec r_out_perp;
	t_vec r_out_parallel;

	r_out_perp = vec_cal((t_vec[2]){*r_in, *n},
			(double[2]){1 * ir, cos_theta * ir}, 2);
	r_out_parallel = vec_cal((t_vec[1]){*n}, (double[1])
			{-1 * sqrt(ft_abs(1.0 - vec_length_squared_(&r_out_perp)))}, 1);
	return (vec_cal((t_vec[2]){r_out_perp, r_out_parallel},
				(double[2]){1, 1}, 2));
}

int				scatter_dielectric(t_material *this, t_ray *ray_in,
		t_hit_record *rec, t_ray *ray_out)
{
	t_vec	target;
	t_vec	ray_in_dir_unit;
	t_vec	ray_in_dir_unit_minus;
	double	refraction_ratio;
	double	theta[2];

	refraction_ratio = this->ir;
	if (rec->front_face)
		refraction_ratio = 1.0 / this->ir;
	ray_in_dir_unit = vec_unit_(&ray_in->dir);
	ray_in_dir_unit_minus =
		vec_cal((t_vec[1]){ray_in_dir_unit}, (double[1]){-1}, 1);
	theta[0] = ft_min(vec_dot_(&ray_in_dir_unit_minus, &rec->n), 1.0);
	theta[1] = sqrt(1 - pow(theta[0], 2));
	if (refraction_ratio * theta[1] > 1.0)
		target = reflect_(&ray_in_dir_unit, &rec->n);
	else
		target = refract(&ray_in_dir_unit, &rec->n, refraction_ratio, theta[0]);
	ray_out->origin = rec->p;
	ray_out->dir = target;
	return (1);
}
