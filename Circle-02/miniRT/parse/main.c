#include "main.h"

int ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

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

int ft_isspace(char c)
{
	return (c == 32);
}

int ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int ft_atoi(char **line)
{
	int num;

	num = 0;
	while(!ft_isdigit(**line))
		++(*line);
	while(ft_isdigit(**line))
	{
		num = num * 10 + (**line - '0');
		++(*line);
	}
	return num;
}

double ft_atod(char **line)
{
	double num;
	char* pos;

	num = 0;
	while(!ft_isdigit(**line))
		++(*line);
	while(ft_isdigit(**line) || **line == '.')
	{
		if (**line == '.')
			pos = *line;
		else
			num = num * 10 + (**line - '0');
		++(*line);
	}
	return (num / pow(10, *line - pos - 1));
}

int parse_r(char **line, t_box *box)
{
	if (box->check != 0)
		return 0;
	box->check = 1;
	++(*line);
	box->r.width = ft_atoi(line);
	box->r.height = ft_atoi(line);
	return (1);
}

void parse_add(t_box *box, t_a *a)
{
	a->next = box->a->next;
	box->a->next = a;
}

int parse_a(char **line, t_box *box)
{
	t_a *a;

	a = malloc(sizeof(t_a));
	if (a == NULL)
		return (ERROR);
	++(*line);
	a->val = ft_atod(line);
	a->color.x = ft_atoi(line);
	a->color.y = ft_atoi(line);
	a->color.z = ft_atoi(line);
	parse_add(box, a);
	return (OK);
}

int parse_all(t_box *box)
{
	char *tmp;

	tmp = box->line;
	while(*tmp)
	{
		if (*tmp == 'R')
			parse_r(&tmp, box);
		if (*tmp == 'A')
			parse_a(&tmp, box);
		if (*tmp == 'c')
			break;
		++tmp;
	}
	return (OK);
}

void parse_set(t_box *box)
{
	box->check = 0;
	box->a = malloc(sizeof(t_a));
	box->a->color = (t_color){0, 0, 0};
	box->a->next = NULL;
	box->a->val = 0;
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
	}
	t_a *tmp = box.a->next;
	printf("R w : %d, h : %d\n", box.r.width, box.r.height);
	printf("val : %f, x, y, z : (%f, %f, %f)\n", tmp->val, tmp->color.x, tmp->color.y, tmp->color.z);
	return (0);
}
// R { width, height }
// A { }
// C {{view point}, {normal vector}, FOV}
// sp {{center}, diameter, {color}}
