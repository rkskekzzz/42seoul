/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 18:03:09 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/22 18:07:39 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	vec_min(t_vec v1, t_vec v2)
{
	t_vec out;

	out.x = ft_min(v1.x, v2.x);
	out.y = ft_min(v1.y, v2.y);
	out.z = ft_min(v1.z, v2.z);
	return (out);
}

t_vec	vec_mul(t_vec v1, t_vec v2)
{
	t_vec out;

	out.x = v1.x * v2.x;
	out.y = v1.y * v2.y;
	out.z = v1.z * v2.z;
	return (out);
}

t_vec	vec_mul_(t_vec *v1, t_vec *v2)
{
	t_vec out;

	out.x = v1->x * v2->x;
	out.y = v1->y * v2->y;
	out.z = v1->z * v2->z;
	return (out);
}

t_vec	vec_muln(t_vec v1, double k)
{
	t_vec out;

	out.x = v1.x * k;
	out.y = v1.y * k;
	out.z = v1.z * k;
	return (out);
}

t_vec	vec_divn(t_vec v1, double k)
{
	t_vec out;

	out.x = v1.x / k;
	out.y = v1.y / k;
	out.z = v1.z / k;
	return (out);
}
