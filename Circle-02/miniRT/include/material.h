/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:59:11 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/24 22:11:03 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H
# include "minirt.h"
# include <stdio.h>

typedef struct s_hit_record	t_hit_record;

typedef struct				s_material
{
	t_clr					color;
	double					fuzz;
	double					ir;
	int						(*scatter)(struct s_material *this, t_ray *ray_in,
			t_hit_record *rec, t_ray *ray_out);
}							t_material;

t_material					create_lambertian(t_clr color);
t_material					create_metal(t_clr color, double fuzz);
t_material					create_dielectric(double ir);

int							scatter_lambertian(struct s_material *this,
		t_ray *ray_in, t_hit_record *rec, t_ray *ray_out);
int							scatter_metal(struct s_material *this,
		t_ray *ray_in, t_hit_record *rec, t_ray *ray_out);
int							scatter_dielectric(t_material *this,
		t_ray *ray_in, t_hit_record *rec, t_ray *ray_out);

#endif
