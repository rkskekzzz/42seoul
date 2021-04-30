#include "parse.h"

static void parse_add_c(t_box *box, t_c *c)
{
	c->next = box->c->next;
	box->c->next = c;
}

int parse_c(char **line, t_box *box)
{
	t_c *c;
	int error;

	if (ft_arrsize(line) != 4 || !ft_isnum(line[3]))
		return (ERROR);
	error = 1;
	c = malloc(sizeof(t_c));
	if (c == NULL)
		return (ERROR);
	error &= parse_split(&(c->center), line[1]);
	error &= parse_split(&(c->n), line[2]);
	c->fov = ft_atoi(line[3]);
	if (!error)
		return (ERROR);
	parse_add_c(box, c);
	return (OK);
}
