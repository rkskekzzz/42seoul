/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 18:03:24 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/22 18:05:15 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	random_in_unit_sphere(void)
{
	t_vec out;

	while (1)
	{
		out = vec(r_num(1, -1, 1), r_num(1, -1, 1), r_num(1, -1, 1));
		if (vec_length_squared_(&out) >= 1)
			continue ;
		return (out);
	}
}

t_vec	random_unit_vector(void)
{
	t_vec tmp;

	tmp = random_in_unit_sphere();
	return (vec_unit_(&tmp));
}

t_vec	random_in_hemisphere(t_vec *normal)
{
	t_vec in_unit_sphere;

	in_unit_sphere = random_in_unit_sphere();
	if (vec_dot_(&in_unit_sphere, normal) > 0.0)
		return (in_unit_sphere);
	else
		return (vec_cal((t_vec[1]){in_unit_sphere}, (double[1]){-1}, 1));
}
