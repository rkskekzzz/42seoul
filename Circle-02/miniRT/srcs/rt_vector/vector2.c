/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 18:03:03 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/22 18:08:01 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	vec_cal(t_vec *v, double *a, int n)
{
	t_vec out;

	out = vec(0, 0, 0);
	while (n--)
	{
		out.x += v[n].x * a[n];
		out.y += v[n].y * a[n];
		out.z += v[n].z * a[n];
	}
	return (out);
}

t_vec	vec_add(t_vec v1, t_vec v2)
{
	t_vec out;

	out.x = v1.x + v2.x;
	out.y = v1.y + v2.y;
	out.z = v1.z + v2.z;
	return (out);
}

t_vec	vec_sub(t_vec v1, t_vec v2)
{
	t_vec out;

	out.x = v1.x - v2.x;
	out.y = v1.y - v2.y;
	out.z = v1.z - v2.z;
	return (out);
}

t_vec	vec_sub_(t_vec *v1, t_vec *v2)
{
	t_vec out;

	out.x = v1->x - v2->x;
	out.y = v1->y - v2->y;
	out.z = v1->z - v2->z;
	return (out);
}

t_vec	vec_oppo(t_vec v)
{
	return (vec(-v.x, -v.y, -v.z));
}
