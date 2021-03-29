#include <unistd.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int prtimage()
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	image;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "Hellow World!");
	image.img = mlx_new_image(mlx_ptr, 1920, 1080); // 이미지 객체 생성
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian); // 이미지 주소 할당
	for (int i = 0 ; i < 200 ; i++)
	{
		mlx_pixel_put (mlx_ptr, win_ptr, i, i, 0x00FF0000);
		//my_mlx_pixel_put(&image, i, i, 0x00FF0000);
	}
	//mlx_put_image_to_window(mlx_ptr, win_ptr, image.img, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}


typedef struct	s_vars {
	void		*mlx;
	void		*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	static int i = 0;
	i++;
	if(keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	vars = 0;
	printf("%d : Hello from key_hook!\n", i);
	return (0);
}

int mouse_hook(int button, int x, int y, void *param)
{
	printf("but : %d, x : %d, y : %d, param : %p\n", button, x, y, param);
	return (0);
}

int win_close(int button, t_vars *vars)
{
	printf("but : %d(%p)\n", button, vars);
	//mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int mouse_pos(int button, int x, int y, void *param)
{
	// if (button == 1)
		printf("x : %d, y : %d(%d, %p)\n", x, y, button, param);
	return (0);
}

int exit_hook()
{
	exit(0);
}

int	hooking(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0);
	mlx_hook(vars.win, 4, 1L<<2, mouse_hook, 0);
	mlx_loop(vars.mlx);
	return (0);
}

int main()
{
	//prtimage();
	hooking();
	return (0);
}
