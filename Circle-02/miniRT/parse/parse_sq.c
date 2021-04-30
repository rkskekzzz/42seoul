#include "parse.h"

static void parse_add_sq(t_box *box, t_sq *sq)
{
	sq->next = box->sq->next;
	box->sq->next = sq;
}

int parse_sq(char **line, t_box *box)
{
	t_sq *sq;
	int error;

	if (ft_arrsize(line) != 5 || !ft_isnum(line[3]))
		return (ERROR);
	error = 1;
	sq = malloc(sizeof(t_sq));
	if (sq == NULL)
		return (ERROR);
	error &= parse_split(&(sq->pos), line[1]);
	error &= parse_split(&(sq->n), line[2]);
	error &= parse_split(&(sq->color), line[4]);
	sq->sidesize = ft_atod(line[3]);
	if (!error)
		return (ERROR);
	parse_add_sq(box, sq);
	return (OK);
}
