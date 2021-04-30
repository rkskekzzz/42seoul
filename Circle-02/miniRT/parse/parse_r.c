#include "parse.h"

int parse_r(char **line, t_box *box)
{
	char *tmp;

	if (box->check != 0 || ft_arrsize(line) != 3 || !ft_isnum(line[1]) || !ft_isnum(line[2]))
		return (ERROR);
	box->check = 1;
	box->r.wid = ft_atoi(line[1]);
	box->r.hei = ft_atoi(line[2]);
	return (OK);
}
