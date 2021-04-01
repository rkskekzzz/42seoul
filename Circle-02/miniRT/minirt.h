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
typedef struct s_data
{
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

// vector 구조체
typedef struct s_vec
{
	double x;
	double y;
	double z;
}		t_vec;

typedef struct s_ray
{
	t_vec* orig;
	t_vec* dir;
}	t_ray;

