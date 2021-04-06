#include "minirt.h"

void			my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// key event
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


// close button event
int exit_hook()
{
	exit(0);
}
// void write_color(std::ostream &out, color pixel_color) {
//     // Write the translated [0,255] value of each color component.
//     out << static_cast<int>(255.999 * pixel_color.x()) << ' '
//         << static_cast<int>(255.999 * pixel_color.y()) << ' '
//         << static_cast<int>(255.999 * pixel_color.z()) << '\n';
// }
int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

double hit_sphere(t_vec *center, double radius, t_ray *ray)
{
	t_vec *oc = vec_alloc(ray->origin->x - center->x
						, ray->origin->y - center->y
						, ray->origin->z - center->z);
	double a = vec_dot(ray->dir, ray->dir);
	double half_b = vec_dot(oc, ray->dir);
	double c = vec_dot(oc, oc) - radius * radius;
	double discriminant = half_b*half_b - a*c;
	if (discriminant < 0)
		return -1;
	return ((-half_b - sqrt(discriminant)) / a);
}

int get_color(t_ray *ray)
{
	double t = hit_sphere(vec_alloc(0, 0, -1), 0.5, ray);
	if (t > 0) {
		t_vec *p = ray_at(ray, t);
		t_vec *n = vec_unit_vector(vec_alloc(p->x, p->y, p->z+1));
		return create_trgb(0, 255.999 *((n->x + 1) / 2), 255.999 *((n->y + 1) / 2), 255.999 *((n->z + 1) / 2));
	}
	t_vec *unit_direction = vec_unit_vector(ray->dir);
    t = 1-0.5*(unit_direction->y + 1.0);
	return create_trgb(0, 255.999 * (1-t + 0.5*t),255.999 * (1-t + 0.7*t) ,255.999 * (1-t + 1.0*t) );
}


int prtimage()
{

	int		color;

    double viewport_height = 2.0;
    double viewport_width = (16.0 / 9.0) * viewport_height;
    double focal_length = 1.0;

	t_image	image;
	t_vars	vars;

	image.width = 1600;
	image.height = 900;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, image.width, image.height, "Hellow World!");
	image.img_ptr = mlx_new_image(vars.mlx, image.width, image.height); // 이미지 객체 생성
	image.addr = mlx_get_data_addr(image.img_ptr, &image.bits_per_pixel, &image.line_length, &image.endian); // 이미지 주소 할당

	t_vec *origin;
	t_vec *horizontal;
	t_vec *vertical;
	t_vec *lower_left_corner;

	origin = vec_alloc(0, 0, 0);
	horizontal  = vec_alloc(viewport_width, 0, 0);
	vertical  = vec_alloc(0, viewport_height, 0);
	lower_left_corner = vec_alloc(-viewport_width/2, -viewport_height / 2, -focal_length);


	for (int j = 0  ; j < image.height - 1 ; ++j)
	{
		for (int i = 0 ; i < image.width - 1; ++i)
		{
			double v = (double)j / (image.height - 1);
			double u = (double)i / (image.width - 1);
			t_ray ray;
			t_vec *dir = vec_alloc(-viewport_width/2 + u * viewport_width
								 ,-viewport_height/2 + v * viewport_height
								 ,-focal_length);
			ray.origin = origin;
			ray.dir = dir;
			color = get_color(&ray);
			my_mlx_pixel_put(&image, i, j, color); // 생성한 이미지에 픽셀별 color지정하기
		}
	}
	mlx_put_image_to_window(vars.mlx, vars.win, image.img_ptr, 0, 0); // 생성한 이미지 객체 윈도우에 올리기

	mlx_key_hook(vars.win, key_hook, &vars); // esc close
	mlx_hook(vars.win, 17, 0, exit_hook, 0); // x button close
	mlx_loop(vars.mlx);
	return (0);
}

int main()
{
	prtimage();
	return (0);
}
