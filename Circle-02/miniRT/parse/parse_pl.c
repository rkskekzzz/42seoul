#include "parse.h"

int parse_pl(char **line, t_box *box)
{
	t_parsed	parsed;

	if (ft_arrsize(line) != 4)
		return (ERROR);
	return (parse_split(&(parsed.pl.pos), line[1]) && \
			parse_split(&(parsed.pl.n), line[2]) && \
			parse_split(&(parsed.pl.color), line[3]) && \
			parsed_list_add(box, pl, parsed));
}
