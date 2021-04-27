#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# define ERROR -1
# define OK 1

typedef struct s_color
{
	double	x;
	double	y;
	double	z;
}	t_color;

typedef struct s_c
{
	double		val;
	t_color		color;
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
	char	line[4194304];
	int		check;
	t_r		r;
	t_a		*a;
}	t_box;

#endif
