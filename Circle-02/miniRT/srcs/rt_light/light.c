/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:29:45 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/24 21:45:24 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			in_shadow(t_minirt *mini, t_ray *light_ray,
		t_light *light, t_hit_record *record)
{
	t_hit_record	rec;
	double			light_len;

	light_ray->dir = vec_cal((struct s_vec[2]){light->origin, record->p},
			(double[2]){1, -1}, 2);
	light_ray->origin = vec_cal((struct s_vec[2]){record->p, record->n},
			(double[2]){1, EPSILON}, 2);
	light_len = vec_length_(&light_ray->dir);
	if (hit_world(mini->wrd, light_ray, (double[2]){EPSILON, light_len}, &rec))
		return (OK);
	return (ERROR);
}

t_light		*init_light(void)
{
	t_light	*head;

	head = malloc(sizeof(t_light));
	if (!head)
		return (0);
	head->origin = vec(0, 0, 0);
	head->next = 0;
	return (head);
}

int			add_light(t_light *head, t_pnt origin, t_clr color, double ratio)
{
	t_light *light;

	light = malloc(sizeof(t_light));
	if (!light)
		return (ERROR);
	light->origin = origin;
	light->color = color;
	light->ratio = ratio;
	light->next = head->next;
	head->next = light;
	return (OK);
}

t_clr		light_get(t_minirt *mini, t_hit_record *rec, t_light *light)
{
	t_clr	diffuse;
	t_clr	specular;
	t_vec	dir[3];
	t_ray	light_ray;

	if (in_shadow(mini, &light_ray, light, rec))
		return (vec(0, 0, 0));
	dir[0] = vec_unit(light_ray.dir);
	diffuse = vec_muln(light->color, ft_max(vec_dot(rec->n, dir[0]), 0.0));
	dir[1] = vec_unit(vec_oppo(rec->rayin));
	dir[2] = reflect(vec_oppo(dir[0]), rec->n);
	specular = vec_muln(vec_muln(light->color, 0.25), \
		pow(ft_max(vec_dot(dir[1], dir[2]), 0.0), 28));
	return (vec_muln(vec_add(diffuse, specular), light->ratio * LUMEN));
}

t_clr		phong(t_minirt *mini, t_hit_record *rec)
{
	t_clr		color;
	t_light		*light;

	light = mini->light->next;
	color = vec(0, 0, 0);
	while (light)
	{
		color = vec_add(color, light_get(mini, rec, light));
		light = light->next;
	}
	color = vec_add(color, vec_muln(mini->light->color, mini->light->ratio));
	return (vec_min(vec_mul(color, rec->material->color), vec(1, 1, 1)));
}
