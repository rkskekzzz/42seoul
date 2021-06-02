/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:59:41 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/22 18:01:32 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_screen_check(t_minirt *mini)
{
	int	max_wid;
	int	max_hei;

	if (!mini)
		return (ERROR);
	mlx_get_screen_size(mini->scr.mlx, &max_wid, &max_hei);
	if (max_wid < mini->scr.wid)
		mini->scr.wid = max_wid;
	if (max_hei < mini->scr.hei)
		mini->scr.hei = max_hei;
	return (OK);
}

int		parse_r(char **line, t_minirt *mini)
{
	if ((mini->scr.wid && mini->scr.hei) || \
		ft_arrsize(line) != 3 || \
		!ft_atod(&mini->scr.wid, line[1]) || \
		!ft_atod(&mini->scr.hei, line[2]) || \
		!ft_screen_check(mini))
		return (ERROR);
	return (OK);
}

int		parse_sp(char **line, t_minirt *mini)
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

int		parse_sq(char **line, t_minirt *mini)
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

int		parse_tr(char **line, t_minirt *mini)
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
