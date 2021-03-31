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

typedef struct s_vec
{
	double r;
	double g;
	double b;
}		t_vec;

