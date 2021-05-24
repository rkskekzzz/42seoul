/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambertian.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:31:34 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/24 22:19:19 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_material	create_lambertian(t_vec color)
{
	t_material mat;

	mat.color = vec_divn(color, 255);
	mat.scatter = scatter_lambertian;
	return (mat);
}

int			scatter_lambertian(t_material *this, t_ray *ray_in,
		t_hit_record *rec, t_ray *ray_out)
{
	if (!this || !ray_in)
		return (ERROR);
	t_vec target;

	target = random_in_hemisphere(&rec->n);
	ray_out->origin = rec->p;
	ray_out->dir = target;
	return (OK);
}
