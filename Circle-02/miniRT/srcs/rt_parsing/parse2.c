#include "minirt.h"

int	parse_r(char **line, t_minirt *mini)
{
	if ((mini->scr.wid && mini->scr.hei) || \
		ft_arrsize(line) != 3 || \
		!ft_atod(&mini->scr.wid, line[1]) || \
		!ft_atod(&mini->scr.hei, line[2]))
		return (ERROR);
	return (OK);
}

int	parse_sp(char **line, t_minirt *mini)
{
	t_vec	c;
	t_vec	color;
	double	r;

	if (ft_arrsize(line) != 4 || \
		!ft_atod(&r, line[2]) || \
		!parse_split(&c, line[1]) || \
		!parse_split(&color, line[3]))
		return (ERROR);
	return (add_world(mini->wrd, \
			create_sphere(c, r), hit_sphere, \
			create_metal(color, (double)rand() / (double)RAND_MAX)));
}

int	parse_sq(char **line, t_minirt *mini)
{
	t_pnt	c;
	t_vec	n;
	t_clr	color;
	double	side;

	if (ft_arrsize(line) != 5 || \
		!ft_atod(&side, line[3]) || \
		!parse_split(&c, line[1]) || \
		!parse_split(&n, line[2]) || \
		!parse_split(&color, line[4]))
		return (ERROR);
	return (add_world(mini->wrd, \
			create_square(c, n, side), hit_square, \
			create_metal(color, (double)rand() / (double)RAND_MAX)));
}

int	parse_tr(char **line, t_minirt *mini)
{
	t_vec	p1;
	t_vec	p2;
	t_vec	p3;
	t_clr	color;

	if (ft_arrsize(line) != 5 || \
		!parse_split(&p1, line[1]) || \
		!parse_split(&p2, line[2]) || \
		!parse_split(&p3, line[3]) || \
		!parse_split(&color, line[4]))
		return (ERROR);
	return (add_world(mini->wrd, \
			create_triangle(p1, p2, p3), hit_triangle, \
			create_metal(color, (double)rand() / (double)RAND_MAX)));
}
