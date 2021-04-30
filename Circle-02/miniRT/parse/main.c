#include "main.h"
#include "parse.h"

int printf_error()
{
	printf("parsing error\n");
	return (ERROR);
}

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
	if (ft_arrsize(tmp) != 3 ||!ft_isnum(tmp[0]) || !ft_isnum(tmp[1]) || !ft_isnum(tmp[2]))
		return (ERROR);
	input->x = ft_atod(tmp[0]);
	input->y = ft_atod(tmp[1]);
	input->z = ft_atod(tmp[2]);
	ft_free_split(tmp, ft_arrsize(tmp));
	return (OK);
}

void parser_init(int (*parser[9])(char **, t_box *))
{
	parser[r] = parse_r;
	parser[a] = parse_a;
	parser[c] = parse_c;
	parser[l] = parse_l;
	parser[sp] = parse_sp;
	parser[pl] = parse_pl;
	parser[sq] = parse_sq;
	parser[cy] = parse_cy;
	parser[tr] = parse_tr;
}

int parse_all(t_box *box)
{
	int i;
	char **data;
	char **line;
	int (*parser[9])(char **, t_box *);

	data = ft_split(box->line, "\n");
	while(*data)
	{
		line = ft_split(*data, WHITESPACE);
		i = -1;
		while(++i < 9)
			if (!ft_strncmp(line[0],
							(char[9][2]){"R", "A", "c", "l", "pl", "sp"
										,"sq", "cy", "tr"}[i]) &&
				parser[i](line, box))
				break;
		if (i == 9)
			return (printf_error());
		ft_free_split(line, ft_arrsize(line));
		++data;
	}
	return (OK);
}

int main(int argc, char **argv)
{
	t_box box;

	ft_memset(&box, 0 , sizeof(t_box));
	if (argc == 2)
	{
		if (parsing(argv[1], &box) < 0)
			return (0);
		parse_all(&box);
		// t_a tmp = box.a->next;
		// t_c tmp2 = box.c->next;
		// printf("R w : %d, h : %d\n", box.r.wid, box.r.hei);
		// if(tmp != NULL) // && tmp2 != NULL)
		// {
		// 	printf("val : %f, x, y, z : (%f, %f, %f)\n", tmp->val, tmp->color.x, tmp->color.y, tmp->color.z);
		// 	printf("center : (%f, %f, %f), n : (%f, %f, %f), fov : %d\n", tmp2->center.x, tmp2->center.y, tmp2->center.z, tmp2->n.x, tmp2->n.y, tmp2->n.z, tmp2->fov);
		// 	tmp2 = tmp2->next;
		// 	printf("center : (%f, %f, %f), n : (%f, %f, %f), fov : %d\n", tmp2->center.x, tmp2->center.y, tmp2->center.z, tmp2->n.x, tmp2->n.y, tmp2->n.z, tmp2->fov);
		// 	printf("center : (%f, %f, %f)\n", box.tr->next->po1.x, box.tr->next->po1.y, box.tr->next->po1.z);
		// }
	}
	return (0);
}

