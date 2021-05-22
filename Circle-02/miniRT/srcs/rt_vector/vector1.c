/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 18:02:43 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/22 18:02:57 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	ray_at(t_ray *ray, double t)
{
	return (vec(ray->origin.x + ray->dir.x * t,
				ray->origin.y + ray->dir.y * t,
				ray->origin.z + ray->dir.z * t));
}

void	vec_print(char *str, t_vec *vec)
{
	printf("[%s : %.2f, %.2f, %.2f]\n", str, vec->x, vec->y, vec->z);
}

t_vec	vec(double x, double y, double z)
{
	t_vec out;

	out.x = x;
	out.y = y;
	out.z = z;
	return (out);
}
