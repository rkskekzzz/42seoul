#include "parse.h"

int parse_l(char **line, t_box *box)
{
	t_parsed	parsed;

	if (ft_arrsize(line) != 4 || !ft_isnum(line[2]))
		return (ERROR);
	parsed.l.brightness = ft_atod(line[2]);
	return (OK);
	return (parse_split(&(parsed.l.pos), line[1]) && \
			parse_split(&(parsed.l.color), line[3]) && \
			parsed_list_add(box, l, parsed));
}
