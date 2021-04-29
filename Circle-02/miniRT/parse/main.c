#include "main.h"

int parsing(char *file, t_box *box)
{
	char ch[1];
	int size;
	int fd;
	int i = 0;

	fd = open(file, O_RDONLY);
	size = ft_strlen(file);
	if (fd < 0 || size < 3 || file[size - 1] != 't' || file[size - 2] != 'r' || file[size - 3] != '.')
		return (ERROR);
	size = read(fd, &ch, 1);
	while(size)
	{
		box->line[i++] = ch[0];
		size = read(fd, &ch, 1);
	}
	return (size);
}

void parse_add_a(t_box *box, t_a *a)
{
	a->next = box->a->next;
	box->a->next = a;
}

void parse_add_c(t_box *box, t_c *c)
{
	c->next = box->c->next;
	box->c->next = c;
}

void parse_add_l(t_box *box, t_l *l)
{
	l->next = box->l->next;
	box->l->next = l;
}

/***************************** parsing function ********************************/

int parse_split(t_vec *input, char *line)
{
	char **tmp;

	tmp = ft_split(line, ",");
	if (ft_arrsize(tmp) != 3 || !ft_isnum(tmp[0]) || !ft_isnum(tmp[1]) || !ft_isnum(tmp[2]))
		return (ERROR);
	input->x = ft_atod(tmp[0]);
	input->y = ft_atod(tmp[1]);
	input->z = ft_atod(tmp[2]);
	ft_free_split(tmp, ft_arrsize(tmp));
	return (OK);
}

int parse_r(char **line, t_box *box)
{
	char *tmp;
	if (box->check != 0 || ft_arrsize(line) != 3 ||
		!ft_isnum(line[1]) || !ft_isnum(line[2]))
		return (ERROR);
	box->check = 1;
	box->r.width = ft_atoi(line[1]);
	box->r.height = ft_atoi(line[1]);
	return (1);
}

int parse_a(char **line, t_box *box)
{
	t_a *a;
	char **tmp;

	a = malloc(sizeof(t_a));
	if (a == NULL)
		return (ERROR);
	a->val = ft_atod(line[1]);
	parse_split(&(a->color), line[2]);
	parse_add_a(box, a);
	return (OK);
}

// int parse_c(char **line, t_box *box)
// {
// 	t_c *c;
// 	char *tmp;

// 	c = malloc(sizeof(t_c));
// 	if (c == NULL)
// 		return (ERROR);
// 	tmp = line[1];
// 	c->center.x = ft_atod(&tmp);
// 	c->center.y = ft_atod(&tmp);
// 	c->center.z = ft_atod(&tmp);
// 	tmp = line[2];
// 	c->n.x = ft_atod(&tmp);
// 	c->n.y = ft_atod(&tmp);
// 	c->n.z = ft_atod(&tmp);
// 	tmp = line[3];
// 	c->fov = ft_atoi(&tmp);
// 	if (box->check == ERROR)
// 		return (ERROR);
// 	parse_add_c(box, c);
// 	return (OK);
// }

// int parse_l(char **line, t_box *box)
// {
// 	t_l *l;
// 	char *tmp;

// 	l = malloc(sizeof(t_l));
// 	if (l == NULL)
// 		return (ERROR);
// 	tmp = line[1];
// 	l->pos.x = ft_atod(&tmp);
// 	l->pos.y = ft_atod(&tmp);
// 	l->pos.z = ft_atod(&tmp);
// 	tmp = line[2];
// 	l->brightness = ft_atod(&tmp);
// 	tmp = line[3];
// 	l->color.x = ft_atod(&tmp);
// 	l->color.y = ft_atod(&tmp);
// 	l->color.z = ft_atod(&tmp);
// 	if (box->check == ERROR)
// 		return (ERROR);
// 	parse_add_c(box, c);
// 	return (OK);
// }

int parse_all(t_box *box)
{
	char **data;
	char **oneline;

	data = ft_split(box->line, "\n");
	while(*data)
	{
		oneline = ft_split(*data, WHITESPACE);
		if (!ft_strncmp(oneline[0], "R"))
			parse_r(oneline, box);
		if (!ft_strncmp(oneline[0], "A"))
			parse_a(oneline, box);
		// if (!ft_strncmp(oneline[0], "c"))
		// 	parse_c(oneline, box);
		++data;
		ft_free_split(oneline, ft_arrsize(oneline));
	}
	return (OK);
}

/***************************** parsing function ********************************/

void parse_set(t_box *box)
{
	box->check = 0;
	box->a = malloc(sizeof(t_a));
	box->a->color = (t_color){0, 0, 0};
	box->a->next = NULL;
	box->a->val = 0;
	box->c = malloc(sizeof(t_c));
	box->c->center = (t_point){0, 0, 0};
	box->c->n = (t_vec){0, 0, 0};
	box->c->fov = 0;
	box->c->next = NULL;
	box->l = malloc(sizeof(t_l));
	box->l->pos = (t_point){0, 0, 0};
	box->l->brightness = 0;
	box->l->color = (t_color){0, 0, 0};
	box->l->next = NULL;
}

int main(int argc, char **argv)
{
	t_box box;

	parse_set(&box);
	if (argc == 2)
	{
		if (parsing(argv[1], &box) < 0)
			return (0);
		parse_all(&box);
		t_a *tmp = box.a->next;
		// t_c *tmp2 = box.c->next;
		printf("R w : %d, h : %d\n", box.r.width, box.r.height);
		if(tmp != NULL) // && tmp2 != NULL)
		{
			printf("val : %f, x, y, z : (%f, %f, %f)\n", tmp->val, tmp->color.x, tmp->color.y, tmp->color.z);
			// sprintf("center : (%f, %f, %f), n : (%f, %f, %f), fov : %d\n", tmp2->center.x, tmp2->center.y, tmp2->center.z, tmp2->n.x, tmp2->n.y, tmp2->n.z, tmp2->fov);
		}
	}
	return (0);
}


// R { width, height }
// A { }
// C {{view point}, {normal vector}, FOV}
// sp {{center}, diameter, {color}}
// 문자열 전부 입력받는다
//

