#include "parse.h"

static void parse_add_l(t_box *box, t_l *l)
{
	l->next = box->l->next;
	box->l->next = l;
}

int parse_l(char **line, t_box *box)
{
	t_l *l;
	int error;

	if (ft_arrsize(line) != 4 || !ft_isnum(line[2]))
		return (ERROR);
	error = 1;
	l = malloc(sizeof(t_l));
	if (l == NULL)
		return (ERROR);
	error &= parse_split(&(l->pos), line[1]);
	error &= parse_split(&(l->color), line[3]);
	l->brightness = ft_atod(line[2]);
	if (!error)
		return (ERROR);
	parse_add_l(box, l);
	return (OK);
}
