#include "parse.h"

static void parse_add_pl(t_box *box, t_pl *pl)
{
	pl->next = box->pl->next;
	box->pl->next = pl;
}

int parse_pl(char **line, t_box *box)
{
	t_pl *pl;
	int error;

	if (ft_arrsize(line) != 4)
		return (ERROR);
	error = 1;
	pl = malloc(sizeof(t_pl));
	if (pl == NULL)
		return (ERROR);
	error &= parse_split(&(pl->pos), line[1]);
	error &= parse_split(&(pl->n), line[2]);
	error &= parse_split(&(pl->color), line[3]);
	if (!error)
		return (ERROR);
	parse_add_pl(box, pl);
	return (OK);
}
