#include "parse.h"

static void parse_add_sp(t_box *box, t_sp *sp)
{
	sp->next = box->sp->next;
	box->sp->next = sp;
}

int parse_sp(char **line, t_box *box)
{
	t_sp *sp;
	int error;

	if (ft_arrsize(line) != 4 || !ft_isnum(line[2]))
		return (ERROR);
	error = 1;
	sp = malloc(sizeof(t_sp));
	if (sp == NULL)
		return (ERROR);
	error &= parse_split(&(sp->pos), line[1]);
	error &= parse_split(&(sp->color), line[3]);
	sp->diameter = ft_atoi(line[2]);
	if (!error)
		return (ERROR);
	parse_add_sp(box, sp);
	return (OK);
}
