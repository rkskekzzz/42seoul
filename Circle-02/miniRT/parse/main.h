#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# define ERROR -1
# define OK 1

typedef struct s_vec	t_color;
typedef struct s_vec	t_vec;
typedef struct s_vec	t_point;

struct s_vec
{
	double	x;
	double	y;
	double	z;
};

typedef struct s_c
{
	t_point		center;
	t_vec		n;
	int			fov;
	struct s_c	*next;
}	t_c;

typedef struct s_a
{
	double		val;
	t_color		color;
	struct s_a	*next;
}	t_a;

typedef struct s_r
{
	int		width;
	int		height;
}	t_r;

typedef struct s_box
{
	char	line[2000];
	int		check;
	t_r		r;
	t_a		*a;
	t_c		*c;
}	t_box;

#endif
