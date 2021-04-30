#include "parse.h"

int		parse_c(char **line, t_box *box)
{
	t_parsed	parsed;

	if (ft_arrsize(line) != 4 || !ft_isnum(line[3]))
		return (ERROR);
	parsed.c.fov = ft_atoi(line[3]);
	return (parse_split(&(parsed.c.center), line[1]) && \
			parse_split(&(parsed.c.n), line[2]) && \
			parsed_list_add(box, c, parsed));
}
