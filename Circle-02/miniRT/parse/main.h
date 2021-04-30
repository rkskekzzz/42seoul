#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# define ERROR 0
# define OK 1
// # define BUFFER_SIZE 4194304
# define WHITESPACE "\t\n\v\f\r "
# define ID (char [9][2]){"R", "A", "c", "l", "pl" "sp", "sq", "cy", "tr"}

typedef struct s_vec	t_color;
typedef struct s_vec	t_vec;
typedef struct s_vec	t_point;

struct s_vec
{
	double	x;
	double	y;
	double	z;
};

typedef enum e_parsable
{
	r = 0, a, c, l, pl, sp, sq, cy, tr
}	t_parsable;

typedef struct s_r
{
	int		wid;
	int		hei;
}	t_r;

typedef struct s_a
{
	double		val;
	t_color		color;
}	t_a;

typedef struct s_c
{
	t_point		center;
	t_vec		n;
	int			fov;
}	t_c;

typedef struct s_l
{
	t_point		pos;
	double		brightness;
	t_color		color;
}	t_l;

typedef struct s_sp
{
	t_point		pos;
	double		diameter;
	t_color		color;
}	t_sp;

typedef struct s_pl
{
	t_point		pos;
	t_vec		n;
	t_color		color;
}	t_pl;

typedef struct s_sq
{
	t_point		pos;
	t_vec		n;
	double		sidesize;
	t_color		color;
}	t_sq;

typedef struct s_cy
{
	t_point		pos;
	t_vec		n;
	double		diameter;
	double		hei;
	t_color		color;
}	t_cy;

typedef struct s_tr
{
	t_point		po1;
	t_point		po2;
	t_point		po3;
	t_color		color;
}	t_tr;

typedef struct s_box
{
	char	line[2000];
	t_list	parsed[9];
}	t_box;

typedef union u_parsed
{
	t_r		r;
	t_c		c;
	t_a		a;
	t_l		l;
	t_sp	sp;
	t_pl	pl;
	t_sq	sq;
	t_cy	cy;
	t_r		tr;
}		t_parsed;

typedef struct s_list
{
	t_parsed data;
	struct s_list *next;
}	t_list;

int ft_strlen(char *str);
int ft_arrsize(char **arr);
int		ft_strchr(const char *s, int c);
char **ft_split(char const *s, char *delim);
char **ft_free_split(char **s, int i);
int	ft_strncmp(const char *s1, const char *s2);
int parse_split(t_vec *input, char *line);
int ft_atoi(char *line);
double ft_atod(char *line);

int  ft_isdigit(char c);
int  ft_isspace(char c);
int  ft_isnum(char *str);
void *ft_memset(void *dest, int value, size_t size);
#endif
