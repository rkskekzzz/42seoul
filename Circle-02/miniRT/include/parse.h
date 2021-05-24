/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:05:39 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/24 22:14:58 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "minirt.h"
# include <fcntl.h>
# define WHITESPACE "\t\n\v\f\r "

typedef struct s_minirt		t_minirt;

typedef enum				e_parsable
{
	r = 0,
	a,
	c,
	l,
	sp,
	pl,
	sq,
	cy,
	tr
}							t_parsable;

typedef struct				s_r
{
	int						wid;
	int						hei;
}							t_r;

typedef struct				s_a
{
	double						val;
	t_clr						color;
}							t_a;

typedef struct				s_c
{
	t_pnt					center;
	t_vec					n;
	int						fov;
}							t_c;

typedef struct				s_l
{
	t_pnt						pos;
	double						brightness;
	t_clr						color;
}							t_l;

typedef struct				s_sp
{
	t_pnt						pos;
	double						diameter;
	t_clr						color;
}							t_sp;

typedef struct				s_pl
{
	t_pnt						pos;
	t_vec						n;
	t_clr						color;
}							t_pl;

typedef struct				s_sq
{
	t_pnt						pos;
	t_vec						n;
	double						sidesize;
	t_clr						color;
}							t_sq;

typedef struct				s_cy
{
	t_pnt						pos;
	t_vec						n;
	double						diameter;
	double						hei;
	t_clr						color;
}							t_cy;

typedef struct				s_tr
{
	t_pnt						po1;
	t_pnt						po2;
	t_pnt						po3;
	t_clr						color;
}							t_tr;

typedef union				u_parsed
{
	t_r						r;
	t_c						c;
	t_a						a;
	t_l						l;
	t_sp					sp;
	t_pl					pl;
	t_sq					sq;
	t_cy					cy;
	t_tr					tr;
}							t_parsed;

typedef struct				s_parsed_list
{
	t_parsed					id;
	struct s_parsed_list		*next;
}							t_parsed_list;

typedef struct				s_box
{
	char						line[2000];
	t_parsed_list				parsed[9];
}							t_box;

void						makebmp(t_minirt *mini);
int							printf_ok(char *s);
int							printf_error(char *s);
int							input(int argc, char **argv, t_minirt *mini);
int							parse_split(t_vec *input, char *line);
int							parsed_list_add(t_minirt *mini,
		t_parsable index, t_parsed parsed);

int							parse_r(char **line, t_minirt *mini);
int							parse_a(char **line, t_minirt *mini);
int							parse_c(char **line, t_minirt *mini);
int							parse_l(char **line, t_minirt *mini);
int							parse_pl(char **line, t_minirt *mini);
int							parse_sp(char **line, t_minirt *mini);
int							parse_sq(char **line, t_minirt *mini);
int							parse_cy(char **line, t_minirt *mini);
int							parse_tr(char **line, t_minirt *mini);

#endif
