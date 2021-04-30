#include "main.h"
#include "parse.h"

int parsing(char *file, t_box *box)
{
	char ch[1];
	int s;
	int fd;
	int i = 0;

	fd = open(file, O_RDONLY);
	s = ft_strlen(file);
	if (fd < 0 || s < 3 || file[s - 1] != 't' || file[s - 2] != 'r' || file[s - 3] != '.')
		return (ERROR);
	s = read(fd, &ch, 1);
	while(s)
	{
		box->line[i++] = ch[0];
		s = read(fd, &ch, 1);
	}
	return (s);
}

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

int parse_all(t_box *box)
{
	char **data;
	char **oneline;
	int error;

	data = ft_split(box->line, "\n");
	while(*data)
	{
		oneline = ft_split(*data, WHITESPACE);
		if (!ft_strncmp(oneline[0], "R"))
			parse_r(oneline, box);
		if (!ft_strncmp(oneline[0], "A"))
			parse_a(oneline, box);
		if (!ft_strncmp(oneline[0], "c"))
			parse_c(oneline, box);
		if (!ft_strncmp(oneline[0], "l"))
			parse_l(oneline, box);
		if (!ft_strncmp(oneline[0], "pl"))
			parse_pl(oneline, box);
		if (!ft_strncmp(oneline[0], "sp"))
			parse_sp(oneline, box);
		if (!ft_strncmp(oneline[0], "sq"))
			parse_sq(oneline, box);
		if (!ft_strncmp(oneline[0], "cy"))
			parse_cy(oneline, box);
		if (!ft_strncmp(oneline[0], "tr"))
			parse_tr(oneline, box);
		++data;
		ft_free_split(oneline, ft_arrsize(oneline));
	}
	return (OK);
}

/***************************** parsing function ********************************/

void parse_set(t_box *box)
{
	ft_memset(box, 0, sizeof(t_box));
	box->a = malloc(sizeof(t_a));
	box->c = malloc(sizeof(t_c));
	box->l = malloc(sizeof(t_l));
	box->pl = malloc(sizeof(t_pl));
	box->sp = malloc(sizeof(t_sp));
	box->sq = malloc(sizeof(t_sq));
	box->cy = malloc(sizeof(t_cy));
	box->tr = malloc(sizeof(t_tr));
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
		t_c *tmp2 = box.c->next;
		printf("R w : %d, h : %d\n", box.r.wid, box.r.hei);
		if(tmp != NULL) // && tmp2 != NULL)
		{
			printf("val : %f, x, y, z : (%f, %f, %f)\n", tmp->val, tmp->color.x, tmp->color.y, tmp->color.z);
			printf("center : (%f, %f, %f), n : (%f, %f, %f), fov : %d\n", tmp2->center.x, tmp2->center.y, tmp2->center.z, tmp2->n.x, tmp2->n.y, tmp2->n.z, tmp2->fov);
			tmp2 = tmp2->next;
			printf("center : (%f, %f, %f), n : (%f, %f, %f), fov : %d\n", tmp2->center.x, tmp2->center.y, tmp2->center.z, tmp2->n.x, tmp2->n.y, tmp2->n.z, tmp2->fov);
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

