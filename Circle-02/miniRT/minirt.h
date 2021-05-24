/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:52:31 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/22 16:53:24 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "vector.h"
# include "library.h"
# include "material.h"
# include "light.h"
# include "object.h"
# include "parse.h"
# include "event.h"
# include "bmp.h"

# define MAX_DEPTH 50
# define ERROR 0
# define OK 1
# define EPSILON 1e-6
# define LUMEN 3

typedef struct s_world	t_wold;

/*
**camera 구조체
*/

typedef struct s_camera
{
	t_pnt	pos;
	t_vec	hor;
	t_vec	ver;
	t_vec	low_left_corner;
	double	view_width;
	double	view_height;
	double	fov;
	double	lens_radius;
	t_vec	u;
	t_vec	v;
	t_vec	w;
	void 	*img;
	char	*img_addr;
	struct s_camera	*next;
} 				t_camera;

// image data 구조체
typedef struct s_screen
{
	void	*mlx;
	void	*win;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	wid;
	double	hei;
	int		anti;
}		t_screen;

// the everything...
typedef struct s_minirt
{
	t_screen	scr;
	t_world		*wrd;
	t_camera	*cam;
	t_camera	*curr_cam;
	t_light		*light;
	int			save;

}		t_minirt;

t_camera	*init_camera();
int			add_camera(t_minirt *mini, t_vec lookfrom, t_vec dir, double fov);
void	draw(t_minirt *m);
int		render(t_minirt *mini);
int		anti(t_minirt *mini, int wdx, int hdx);
t_clr 	phong(t_minirt *mini, t_hit_record *rec);
#endif
