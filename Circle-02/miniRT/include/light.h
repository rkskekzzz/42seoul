#ifndef LIGHT_H
# define LIGHT_H
# include "minirt.h"
# define LIGHT_POINT 1

typedef struct s_light
{
	t_pnt	origin;
	t_clr	color;
	double	ratio;
	struct s_light *next;
}	t_light;

t_light	*init_light();
int		add_light(t_light *head, t_pnt origin, t_clr color, double ratio);

#endif
