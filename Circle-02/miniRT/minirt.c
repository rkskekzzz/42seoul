#include <unistd.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



typedef struct	s_vars {
	void		*mlx;
	void		*win;
}				t_vars;

typedef struct s_data
{
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

int exit_hook();
int mouse_hook(int button, int x, int y, void *param);
int	key_hook(int keycode, t_vars *vars);

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int prtimage()
{
	int		img_width;
	int		img_height;
	int		color;
	// clock_t start;

	img_width = 1080;
	img_height = 1920;

	t_data	image;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, img_height, img_width, "Hellow World!");
	image.img = mlx_new_image(vars.mlx, img_height, img_width); // 이미지 객체 생성
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian); // 이미지 주소 할당
	for (int i = 0 ; i < img_height - 1 ; ++i)
	{
		for (int j = 0 ; j < img_width - 1; ++j)
		{
			double r = (double)(img_width - j) / (img_width - 1);
			double g = (double)(i) / (img_height - 1);
			double b = 1;
			color = (int)(255.999 * r) * 65536 + (int)(255.999 * g) * 255 + (int)(255.999 * b);
			my_mlx_pixel_put(&image, i, j, color);
		}
		//mlx_pixel_put (vars.mlx, vars.win, i, i, 0x00FF0000);
	}
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars); // esc close
	mlx_hook(vars.win, 17, 0, exit_hook, 0); // x button close
	mlx_hook(vars.win, 4, 1L<<2, mouse_hook, 0); // mouse pointer
	mlx_loop(vars.mlx);
	return (0);
}



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

// 마우스 위치 찍기
int mouse_hook(int button, int x, int y, void *param)
{
	printf("but : %d, x : %d, y : %d, param : %p\n", button, x, y, param);
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
	mlx_key_hook(vars.win, key_hook, &vars); // esc close
	mlx_hook(vars.win, 17, 0, exit_hook, 0); // x button close
	mlx_hook(vars.win, 4, 1L<<2, mouse_hook, 0); // mouse pointer
	mlx_loop(vars.mlx);
	return (0);
}

int main()
{
	prtimage();
	//hooking();
	return (0);
}
