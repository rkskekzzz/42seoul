#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# define ERROR -1
# define OK 1
# define WHITESPACE "\t\n\v\f\r "

typedef struct s_vec	t_color;
typedef struct s_vec	t_vec;
typedef struct s_vec	t_point;

struct s_vec
{
	double	x;
	double	y;
	double	z;
};

typedef struct s_l
{
	t_point		pos;
	double		brightness;
	t_color		color;
	struct s_l	*next;
}	t_l;

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
	t_l		*l;
}	t_box;

int ft_strlen(char *str);
int ft_arrsize(char **arr);
char **ft_split(char const *s, char *delim);
char **ft_free_split(char **s, int i);
int	ft_strncmp(const char *s1, const char *s2);

int ft_atoi(char *line);
double ft_atod(char *line);

int ft_isdigit(char c);
int ft_isspace(char c);
int ft_isnum(char *str);

#endif
