#include "parse.h"

int parse_tr(char **line, t_box *box)
{
	t_parsed	parsed;

	if (ft_arrsize(line) != 5)
		return (ERROR);
	return (parse_split(&(parsed.tr.po1), line[1]) && \
			parse_split(&(parsed.tr.po2), line[2]) && \
			parse_split(&(parsed.tr.po3), line[3]) && \
			parse_split(&(parsed.tr.color), line[4]) && \
			parsed_list_add(box, tr, parsed));
}
