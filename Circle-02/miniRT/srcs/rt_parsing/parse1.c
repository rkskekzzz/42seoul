/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:58:49 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/22 17:59:30 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		parse_a(char **line, t_minirt *mini)
{
	if (mini->light->origin.x == 1 || \
		ft_arrsize(line) != 3 || \
		!ft_atod(&mini->light->origin.x, "1") || \
		!ft_atod(&mini->light->ratio, line[1]) || \
		!parse_split(&mini->light->color, line[2]))
		return (ERROR);
	mini->light->color = vec_divn(mini->light->color, 255);
	return (OK);
}

int		parse_c(char **line, t_minirt *mini)
{
	t_vec	c;
	t_vec	dir;
	double	fov;

	if (ft_arrsize(line) != 4 || \
		!ft_atod(&fov, line[3]) || \
		!parse_split(&c, line[1]) || \
		!parse_split(&dir, line[2]))
		return (ERROR);
	return (add_camera(mini, \
			c, dir, fov));
}

int		parse_l(char **line, t_minirt *mini)
{
	t_pnt	c;
	t_clr	color;
	double	ratio;

	if (ft_arrsize(line) != 4 || \
		!ft_atod(&ratio, line[2]) || \
		!parse_split(&c, line[1]) || \
		!parse_split(&color, line[3]))
		return (ERROR);
	return (add_light(mini->light, \
			c, vec_divn(color, 255), ratio));
}

int		parse_pl(char **line, t_minirt *mini)
{
	t_pnt	c;
	t_vec	n;
	t_clr	color;

	if (ft_arrsize(line) != 4 || \
		!parse_split(&c, line[1]) || \
		!parse_split(&n, line[2]) || \
		!parse_split(&color, line[3]))
		return (ERROR);
	return (add_world(mini->wrd, \
			create_plane(c, n), hit_plane, \
			create_metal(color, (double)rand() / (double)RAND_MAX)));
}

int		parse_cy(char **line, t_minirt *mini)
{
	t_pnt	c;
	t_vec	n;
	t_clr	color;
	double	r;
	double	h;

	if (ft_arrsize(line) != 6 || \
		!ft_atod(&r, line[3]) || \
		!ft_atod(&h, line[4]) || \
		!parse_split(&c, line[1]) || \
		!parse_split(&n, line[2]) || \
		!parse_split(&color, line[5]))
		return (ERROR);
	return (add_world(mini->wrd, \
			create_cylinder(c, n, r, h), hit_cylinder, \
			create_metal(color, (double)rand() / (double)RAND_MAX)));
}
