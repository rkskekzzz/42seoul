#include "minirt.h"

static void	event(t_minirt *mini)
{
	mlx_key_hook(mini->scr.win, key_hook, mini);  // esc close
	mlx_hook(mini->scr.win, 17, 0, exit_hook, 0); // x button close
}

static void	setting(t_minirt *mini)
{
	t_camera	*c;

	mini->scr.mlx = mlx_init();
	mini->scr.win = mlx_new_window(
		mini->scr.mlx, mini->scr.wid, mini->scr.hei, "이게 미니 알티다");
	mini->scr.anti = 0;
	c = mini->cam;
	while (c->next)
		c = c->next;
	c->next = mini->cam->next;
	mini->curr_cam = mini->cam->next;
	event(mini);
}

static int	minirt(t_minirt *mini)
{
	// clock_t	start, end;
	setting(mini);
	// start = clock();
	draw(mini);
	// end = clock();
	// printf("time : %f\n",(double)(end - start) / CLOCKS_PER_SEC);
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
		return (ERROR);
	minirt(&mini);
	return (0);
}
