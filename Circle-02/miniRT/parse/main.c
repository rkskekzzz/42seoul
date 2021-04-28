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

int ft_atoi(char **line, t_box *box)
{
	int num;

	num = 0;
	while(!ft_isdigit(**line))
		++(*line);
	while(**line && **line == ',')
	{
		if (ft_isdigit(**line))
			num = num * 10 + (**line - '0');
		else
		{
			box->check = ERROR;
			break;
		}
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
	--(*line);
	return (num / pow(10, *line - pos - 1));
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

/***************************** parsing function ********************************/

int parse_r(char **line, t_box *box)
{
	if (box->check != 0)
		return 0;
	box->check = 1;
	++(*line);
	box->r.width = ft_atoi(line, box);
	box->r.height = ft_atoi(line, box);
	--(*line);
	return (1);
}

int parse_a(char **line, t_box *box)
{
	t_a *a;

	a = malloc(sizeof(t_a));
	if (a == NULL)
		return (ERROR);
	++(*line);
	a->val = ft_atod(line);
	a->color.x = ft_atoi(line, box);
	a->color.y = ft_atoi(line, box);
	a->color.z = ft_atoi(line, box);
	if (box->check == ERROR)
		return (ERROR);
	parse_add_a(box, a);
	--(*line);
	return (OK);
}

int parse_c(char **line, t_box *box)
{
	t_c *c;

	c = malloc(sizeof(t_a));
	if (c == NULL)
		return (ERROR);
	++(*line);
	c->center.x = ft_atoi(line, box);
	c->center.y = ft_atoi(line, box);
	c->center.z = ft_atoi(line, box);
	c->n.x = ft_atoi(line, box);
	c->n.x = ft_atoi(line, box);
	c->n.x = ft_atoi(line, box);
	c->fov = ft_atoi(line, box);
	parse_add_c(box, c);
	--(*line);
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

/***************************** parsing function ********************************/

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
		t_a *tmp = box.a->next;
		printf("R w : %d, h : %d\n", box.r.width, box.r.height);
		printf("val : %f, x, y, z : (%f, %f, %f)\n", tmp->val, tmp->color.x, tmp->color.y, tmp->color.z);
	}
	return (0);
}


// R { width, height }
// A { }
// C {{view point}, {normal vector}, FOV}
// sp {{center}, diameter, {color}}
