/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:40:38 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/24 22:10:43 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H
# include "minirt.h"

# define LIGHT_POINT 1

typedef struct		s_light
{
	t_pnt				origin;
	t_clr				color;
	double				ratio;
	struct s_light		*next;
}					t_light;

t_light				*init_light();
int					add_light(t_light *head, t_pnt origin,
		t_clr color, double ratio);

#endif
