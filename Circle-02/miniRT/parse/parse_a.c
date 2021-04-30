#include "parse.h"

static void parse_add_a(t_box *box, t_a *a)
{
	a->next = box->a->next;
	box->a->next = a;
}

int parse_a(char **line, t_box *box)
{
	t_a *a;
	int error;

	if (ft_arrsize(line) != 3 || !ft_isnum(line[1]))
		return (ERROR);
	error = 1;
	a = malloc(sizeof(t_a));
	if (a == NULL)
		return (ERROR);
	a->val = ft_atod(line[1]);
	error &= parse_split(&(a->color), line[2]);
	if (!error)
		return (ERROR);
	parse_add_a(box, a);
	return (OK);
}
