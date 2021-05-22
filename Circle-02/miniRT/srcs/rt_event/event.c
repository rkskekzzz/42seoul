/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:06:59 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/22 17:07:01 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	exit_hook(void)
{
	exit(0);
}

int	key_hook(int keycode, t_minirt *mini)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mini->scr.mlx, mini->scr.win);
		exit(0);
		return (0);
	}
	if (keycode == 49)
	{
		mini->curr_cam = mini->curr_cam->next;
		draw(mini);
	}
	return (0);
}
