// 구, 원기둥 등 구조체 생성
#ifndef OBJECT_H
# define OBJECT_H
# include "minirt.h"
# include <stdlib.h>

typedef struct s_sphere
{
	t_pnt	c;
	double	r;
	int		inside;
}				t_sphere;

typedef struct s_plane
{
	t_pnt	c;
	t_vec	n;
}				t_plane;

typedef struct s_square
{
	t_vec	c;
	t_vec	n;
	double	side;
}				t_square;

typedef struct s_cylinder
{
	t_vec	c;
	t_vec	n;
	double	r;
	double	h;
	t_vec	top;
	t_vec	bot;
}				t_cylinder;

typedef struct s_triangle
{
	t_vec	p1;
	t_vec	p2;
	t_vec	p3;
	t_vec	n;
	t_vec	e1;
	t_vec	e2;
	t_vec	e3;
}				t_triangle;

typedef union u_object
{
	t_cylinder	cylinder;
	t_triangle	triangle;
	t_square	square;
	t_sphere	sphere;
	t_plane		plane;
}		t_object;

typedef struct s_material t_material;

typedef struct s_hit_record
{
	t_vec	p;	// ray에서 구위의 점으로 향하는 벡터 p
	t_vec	n;	// 해당 좌표에서의 법선벡터 n
	t_vec	rayin; // 들어오는 ray의 dir
	double	t;	// ray가 구와 충돌한 지점 사이의 크기
	int		front_face;
	struct s_material	*material;
}				t_hit_record;

typedef struct s_world
{
	t_object	obj;
	t_material	material;
	int			(*hit)(struct s_world *this, t_ray *ray, double minmax[2], t_hit_record *out);
	struct s_world		*next;
}				t_world;

t_world		*init_world(void);
int			add_world(t_world *head, t_object obj, int (*hit)(t_world *this, t_ray *ray, double minmax[2], t_hit_record *out), t_material material);
int			hit_world(t_world *head, t_ray *ray, double minmax[2], t_hit_record *out);
void		set_rec(t_world *this, t_ray *ray, t_hit_record *rec);

t_object	create_sphere(t_vec c, double r);
int			hit_sphere(t_world *this, t_ray *ray, double minmax[2], t_hit_record *rec);
//int			get_sphere_t(t_ *this, t_ray *ray, double minmax[2], double *t);

t_object	create_plane(t_pnt c, t_vec n);
int			hit_plane(t_world *this, t_ray *ray, double minmax[2], t_hit_record *rec);
//int			get_plane_t(t_world *this, t_ray *ray, double minmax[2], double *t);
int			_get_plane_t(t_vec *c, t_vec *n, t_ray *ray, double minmax[2], double *t);

t_object	create_square(t_pnt c, t_vec n, double side);
int			hit_square(t_world *this, t_ray *ray, double minmax[2], t_hit_record *rec);
//int			get_square_t(t_world *this, t_ray *ray, double minmax[2], double *t);

t_object	create_cylinder(t_pnt c, t_vec n, double r, double h);
int			hit_cylinder(t_world *this, t_ray *ray, double minmax[2], t_hit_record *rec);
//int			get_cylinder_t(t_cylinder *cy, t_ray *ray, double minmax[2], double *t);

t_object	create_triangle(t_vec p1, t_vec p2, t_vec p3);
int			hit_triangle(t_world *this, t_ray *ray, double minmax[2], t_hit_record *rec);
//int			get_triangle_t(t_triangle *tr, t_ray *ray, double minmax[2], double *t);
#endif
