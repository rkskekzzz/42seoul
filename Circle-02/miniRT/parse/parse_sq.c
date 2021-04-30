#include "parse.h"

int parse_sq(char **line, t_box *box)
{
	t_parsed	parsed;

	if (ft_arrsize(line) != 5 || !ft_isnum(line[3]))
		return (ERROR);
	parsed.sq.sidesize = ft_atod(line[3]);
	return (parse_split(&(parsed.sq.pos), line[1]) && \
			parse_split(&(parsed.sq.n), line[2]) && \
			parse_split(&(parsed.sq.color), line[4]) && \
			parsed_list_add(box, sq, parsed));
}
