#include "parse.h"

int parse_sp(char **line, t_box *box)
{
	t_parsed	parsed;

	if (ft_arrsize(line) != 4 || !ft_isnum(line[2]))
		return (ERROR);
	parsed.sp.diameter = ft_atoi(line[2]);
	return (parse_split(&(parsed.sp.pos), line[1]) && \
			parse_split(&(parsed.sp.color), line[3]) && \
			parsed_list_add(box, sp, parsed));
}
