/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 18:03:17 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/22 18:07:05 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	vec_unit(t_vec v)
{
	double len;

	len = vec_length_(&v);
	if (len == 0)
		len = 1;
	return (vec(v.x / len, v.y / len, v.z / len));
}

t_vec	vec_unit_(t_vec *v)
{
	double len;

	len = vec_length_(v);
	if (len == 0)
		len = 1;
	return (vec(v->x / len, v->y / len, v->z / len));
}

t_vec	reflect(t_vec v, t_vec n)
{
	return (vec_cal((t_vec[2]){v, n}, (double[2]){1, -2 * vec_dot(v, n)}, 2));
}

t_vec	reflect_(t_vec *v, t_vec *n)
{
	return (vec_cal((t_vec[2]){*v, *n},
				(double[2]){1, -2 * vec_dot_(v, n)}, 2));
}
