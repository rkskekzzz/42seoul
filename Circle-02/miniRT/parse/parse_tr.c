#include "parse.h"

static void parse_add_tr(t_box *box, t_tr *tr)
{
	tr->next = box->tr->next;
	box->tr->next = tr;
}

int parse_tr(char **line, t_box *box)
{
	t_tr *tr;

	int error;
	if (ft_arrsize(line) != 5)
		return (ERROR);
	error = 1;
	tr = malloc(sizeof(t_tr));
	if (tr == NULL)
		return (ERROR);

	error &= parse_split(&(tr->po1), line[1]);
	error &= parse_split(&(tr->po2), line[2]);
	error &= parse_split(&(tr->po3), line[3]);
	error &= parse_split(&(tr->color), line[4]);
	if (!error)
		return (ERROR);
	parse_add_tr(box, tr);
	return (OK);
}
