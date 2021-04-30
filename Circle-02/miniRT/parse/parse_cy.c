#include "parse.h"

static void parse_add_cy(t_box *box, t_cy *cy)
{
	cy->next = box->cy->next;
	box->cy->next = cy;
}

int parse_cy(char **line, t_box *box)
{
	t_cy *cy;
	int error;

	if (ft_arrsize(line) != 6 || !ft_isnum(line[3]) || !ft_isnum(line[4]))
		return (ERROR);
	error = 1;
	cy = malloc(sizeof(t_cy));
	if (cy == NULL)
		return (ERROR);
	error &= parse_split(&(cy->pos), line[1]);
	error &= parse_split(&(cy->n), line[2]);
	error &= parse_split(&(cy->color), line[5]);
	cy->diameter = ft_atod(line[3]);
	cy->hei = ft_atod(line[4]);
	if (!error)
		return (ERROR);
	parse_add_cy(box, cy);
	return (OK);
}
