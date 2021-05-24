/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:41:05 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/24 22:10:04 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <math.h>
# include <stdio.h>

typedef struct s_vec	t_clr;
typedef struct s_vec	t_pnt;
typedef struct s_vec	t_vec;

struct					s_vec
{
	double					x;
	double					y;
	double					z;
};

typedef struct			s_ray
{
	t_pnt					origin;
	t_vec					dir;
}						t_ray;

t_vec					ray_at(t_ray *ray, double t);
t_vec					vec(double x, double y, double z);
void					vec_print(char *str, t_vec *vec);

t_vec					vec_cal(t_vec *v, double *a, int n);
t_vec					vec_add(t_vec v1, t_vec v2);
t_vec					vec_sub(t_vec v1, t_vec v2);
t_vec					vec_sub_(t_vec *v1, t_vec *v2);
t_vec					vec_oppo(t_vec v);

t_vec					vec_min(t_vec v1, t_vec v2);
t_vec					vec_mul(t_vec v1, t_vec v2);
t_vec					vec_mul_(t_vec *v1, t_vec *v2);
t_vec					vec_muln(t_vec v1, double k);
t_vec					vec_divn(t_vec v1, double k);

t_vec					vec_cross(t_vec v1, t_vec v2);
t_vec					vec_cross_(t_vec *v1, t_vec *v2);
double					vec_dot(t_vec v1, t_vec v2);
double					vec_dot_(t_vec *v1, t_vec *v2);

t_vec					vec_unit(t_vec vec);
t_vec					vec_unit_(t_vec *vec);
t_vec					reflect(t_vec v, t_vec n);
t_vec					reflect_(t_vec *v, t_vec *n);

t_vec					random_in_unit_sphere(void);
t_vec					random_unit_vector(void);
t_vec					random_in_hemisphere(t_vec *normal);

double					vec_length(t_vec vec);
double					vec_length_(t_vec *vec);
double					vec_length_squared(t_vec vec);
double					vec_length_squared_(t_vec *vec);

#endif
