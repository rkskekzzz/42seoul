/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:01:46 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/22 17:02:41 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <time.h>

t_camera	*init_camera(void)
{
	t_camera	*head;

	head = (t_camera *)malloc(sizeof(t_camera));
	if (!head)
		return (0);
	head->next = 0;
	return (head);
}

int			add_camera(t_minirt *mini, t_vec lookfrom, t_vec dir, double fov)
{
	t_camera	*cam;
	double		aperture;
	double		ratio;

	aperture = 2.0;
	ratio = mini->scr.wid / mini->scr.hei;
	cam = malloc(sizeof(t_camera));
	dir = vec_unit(dir);
	if (!cam)
		return (ERROR);
	cam->pos = lookfrom;
	cam->view_height = 2.0 * tan((fov * M_PI / 180) / 2.0);
	cam->view_width = ratio * cam->view_height;
	cam->w = vec_oppo(dir);
	cam->u = vec_unit(vec_cross(vec(0, 1, 0), cam->w));
	cam->v = vec_cross(cam->w, cam->u);
	cam->hor = vec_muln(cam->u, cam->view_width);
	cam->ver = vec_muln(cam->v, cam->view_height);
	cam->low_left_corner =
		vec_cal((t_vec[4]){lookfrom, cam->hor, cam->ver, cam->w},
									(double[4]){1, -0.5, -0.5, -1}, 4);
	cam->img = 0;
	cam->next = mini->cam->next;
	mini->cam->next = cam;
	return (OK);
}

void		draw(t_minirt *m)
{
	clock_t	start;
	clock_t end;

	if (!m->curr_cam->img)
	{
		m->curr_cam->img = mlx_new_image(m->scr.mlx, m->scr.wid, m->scr.hei);
		m->curr_cam->img_addr = mlx_get_data_addr(m->curr_cam->img,
													&m->scr.bits_per_pixel,
													&m->scr.line_length,
													&m->scr.endian);
		printf("start render!\n");
		start = clock();
		if (m->save == OK)
			makebmp(m);
		render(m);
		end = clock();
		printf("time : %f\n", (double)(end - start) / CLOCKS_PER_SEC);
	}
	mlx_put_image_to_window(m->scr.mlx, m->scr.win, m->curr_cam->img, 0, 0);
}
