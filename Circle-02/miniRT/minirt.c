/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:52:02 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/22 16:52:03 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	event(t_minirt *mini)
{
	mlx_key_hook(mini->scr.win, key_hook, mini);
	mlx_hook(mini->scr.win, 17, 0, exit_hook, 0);
}

static void	setting(t_minirt *mini)
{
	t_camera	*c;

	mini->scr.mlx = mlx_init();
	mini->scr.win = mlx_new_window(
		mini->scr.mlx, mini->scr.wid, mini->scr.hei, "miniRT");
	mini->scr.anti = 0;
	c = mini->cam;
	while (c->next)
		c = c->next;
	mini->curr_cam = c;
	c->next = mini->cam->next;
	event(mini);
}

static int	minirt(t_minirt *mini)
{
	setting(mini);
	draw(mini);
	mlx_loop(mini->scr.mlx);
	return (0);
}

int			init(t_minirt *mini)
{
	ft_memset(mini, 0, sizeof(t_minirt));
	mini->wrd = init_world();
	mini->cam = init_camera();
	mini->light = init_light();
	if (!mini->wrd || !mini->cam || !mini->light)
		return (ERROR);
	return (OK);
}

int			main(int argc, char **argv)
{
	t_minirt	mini;

	if (!init(&mini) || !input(argc, argv, &mini))
		exit(1);
	minirt(&mini);
	// free_all(mini);
	return (0);
}
