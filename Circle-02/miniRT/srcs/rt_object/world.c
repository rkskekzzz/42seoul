/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:52:56 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/22 17:54:53 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_world	*init_world(void)
{
	t_world	*head;

	head = (t_world *)malloc(sizeof(t_world));
	if (!head)
		return (0);
	head->next = 0;
	return (head);
}

int		add_world(t_world *head, t_object obj,
		int (*hit)(t_world *this, t_ray *ray,
			double minmax[2], t_hit_record *out), t_material material)
{
	t_world *new;

	new = (t_world *)malloc(sizeof(t_world) * 1);
	if (!new)
		return (ERROR);
	new->obj = obj;
	new->hit = hit;
	new->material = material;
	new->next = head->next;
	head->next = new;
	return (OK);
}

int		hit_world(t_world *head, t_ray *ray,
		double minmax[2], t_hit_record *out)
{
	t_hit_record	temp_rec;
	t_world			*w;
	int				flag;

	flag = 0;
	w = head;
	while (w->next)
	{
		w = w->next;
		if (w->hit(w, ray, minmax, &temp_rec))
		{
			minmax[1] = temp_rec.t;
			*out = temp_rec;
			flag = 1;
		}
	}
	return (flag);
}

void	set_rec(t_world *this, t_ray *ray, t_hit_record *rec)
{
	rec->rayin = ray->dir;
	rec->front_face = vec_dot_(&ray->dir, &rec->n) < 0;
	if (!rec->front_face)
		rec->n = vec_oppo(rec->n);
	rec->material = &this->material;
}
