#include "minirt.h"

void			my_mlx_pixel_put(t_screen *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}



// close button event

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

double hit_sphere(t_vec center, double radius, t_ray *ray)
{
	t_vec oc;
	vec_cal(&oc, (t_vec[2]){ray->origin, center} \
				,(double[2]){1, -1}, 2);
	double a = vec_dot(&ray->dir, &ray->dir);
	double half_b = vec_dot(&oc, &ray->dir);
	double c = vec_dot(&oc, &oc) - radius * radius;
	double discriminant = half_b*half_b - a*c;
	if (discriminant < 0)
		return -1;
	return ((-half_b - sqrt(discriminant)) / a);
}

int get_color(t_camera *cam, t_ray *ray)
{
	t_vec center;
	vec(&center, 0, 0, -1);
	double t = hit_sphere(center, 0.5, ray);
	if (t > 0) {
		t_vec tmp;
		t_vec p;
		ray_at(&p, ray, t);
		t_vec n;
		vec(&tmp, p.x, p.y, p.z+1);
		vec_unit(&n, &tmp);
		return create_trgb(0, 255.999 *((n.x + 1) / 2), 255.999 *((n.y + 1) / 2), 255.999 *((n.z + 1) / 2));
	}
	t_vec unit_direction;
	vec_unit(&unit_direction, &ray->dir);
    t = 1-0.5*(unit_direction.y + 1.0);
	return create_trgb(0, 255.999 * (1-t + 0.5*t),255.999 * (1-t + 0.7*t) ,255.999 * (1-t + 1.0*t) );
}

void set_camera(t_camera *cam, double height, double ratio)
{
	cam->view_width = ratio * height;
	cam->view_height = height;
	vec(&(cam->focal_length), 0, 0, 1);
	vec(&(cam->pos), 0, 0, 0);
	vec(&(cam->horizon), cam->view_width, 0, 0);
	vec(&(cam->vertical), 0, cam->view_height, 0);
	vec_cal(&(cam->low_left_corner), (t_vec[4]){cam->pos, cam->horizon, cam->vertical, cam->focal_length}, \
									(double[4]){1, -0.5, -0.5, -1}, 4);
	//vec(&(cam.low_left_corner), -view_width/2, -view_height / 2, -focal_length);
}

int render(t_screen *screen)
{
	int			color;
	int			hdx;
	int			wdx;
	t_ray 		ray;
	t_camera	*cam;

	cam = malloc(sizeof(t_camera) * 1);
	set_camera(cam, 2.0, (16.0 / 9.0));

	hdx = -1;
	while (++hdx < (screen->height - 1))
	{
		wdx = -1;
		while (++wdx < (screen->width - 1))
		{
			double v = (double)hdx / (screen->height  - 1);
			double u = (double)wdx / (screen->width - 1);
			ray.origin = cam->pos;
			vec_cal(&ray.dir, (t_vec[3]){cam->low_left_corner, cam->horizon, cam->vertical} \
							, (double[3]){1, u, v}, 3);
			color = get_color(cam, &ray);
			my_mlx_pixel_put(screen, wdx, hdx, color); // 생성한 이미지에 픽셀별 color지정하기
		}
	}
	return (0);
}

void init(t_window *window, t_screen *screen)
{
	screen->width = 1600;
	screen->height = 900;
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, screen->width, screen->height, "Hellow World!");
	screen->ptr = mlx_new_image(window->mlx, screen->width, screen->height); // 이미지 객체 생성
	screen->addr = mlx_get_data_addr(screen->ptr, &screen->bits_per_pixel, &screen->line_length, &screen->endian); // 이미지 주소 할당
}

void event(t_window *window, t_screen *screen)
{
	mlx_key_hook(window->win, key_hook, window); // esc close
	mlx_hook(window->win, 17, 0, exit_hook, 0); // x button close
}

void draw(t_window *window, t_screen *screen)
{
	// t_camera	*cam;

	render(screen);
	mlx_put_image_to_window(window->mlx, window->win, screen->ptr, 0, 0); // 생성한 이미지 객체 윈도우에 올리기
	mlx_loop(window->mlx);
}

int minirt()
{
	t_screen	screen;
	t_window	window;

	init(&window, &screen);
	event(&window, &screen);
	draw(&window, &screen);
	return (0);
}

int main()
{
	//parsing();
	//parsing 에러 체크
	minirt();
	//minirt 에러 체크
	return (0);
}
