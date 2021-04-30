#include "parse.h"

int parse_r(char **line, t_box *box)
{
	if (box->parsed[r].next != NULL || ft_arrsize(line) != 3 || !ft_isnum(line[1]) || !ft_isnum(line[2]))
		return (ERROR);
	box->parsed[r].id.r.wid = ft_atoi(line[1]);
	box->parsed[r].id.r.hei = ft_atoi(line[2]);
	return (OK);
}
