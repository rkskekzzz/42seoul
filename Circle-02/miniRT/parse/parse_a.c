#include "parse.h"

int parse_a(char **line, t_box *box)
{
	t_parsed	parsed;

	if (ft_arrsize(line) != 3 || !ft_isnum(line[1]))
		return (ERROR);
	parsed.a.val = ft_atod(line[1]);
	return (parse_split(&(parsed.a.color), line[2]) && \
			parsed_list_add(box, a, parsed));
}
