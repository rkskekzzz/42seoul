/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 18:03:20 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/22 18:05:48 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vec_length_squared_(t_vec *vec)
{
	return (vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
}

double	vec_length_squared(t_vec vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

double	vec_length_(t_vec *vec)
{
	double len;

	len = vec_length_squared_(vec);
	len = sqrt(len);
	return (len);
}

double	vec_length(t_vec vec)
{
	double len;

	len = vec_length_squared_(&vec);
	len = sqrt(len);
	return (len);
}
