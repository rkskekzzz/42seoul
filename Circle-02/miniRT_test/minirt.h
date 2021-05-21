#include <unistd.h>
#include <mlx.h>
#include <math.h>
#include <stdlib.h>

#include <stdio.h>
#include <time.h>


// mlx 구조체
typedef struct	s_vars
{
	void		*mlx;
	void		*win;
}				t_vars;

// image data 구조체
typedef struct s_image
{
	void 	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}		t_image;

// vector 구조체
typedef struct s_vec
{
	double x;
	double y;
	double z;
}		t_vec;

typedef struct s_ray
{
	t_vec* origin;
	t_vec* dir;
}	t_ray;

void vec_print(t_vec *vec);
t_vec *ray_at(t_ray *ray, double t);
t_vec *vec_alloc(double x, double y, double z);
double vec_dot(t_vec *vec, t_vec *add);
t_vec *vec_unit_vector(t_vec *vec);
void vec_subvec(t_vec *vec, t_vec *add);
