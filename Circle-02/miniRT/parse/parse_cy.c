#include "parse.h"

int parse_cy(char **line, t_box *box)
{
	t_parsed	parsed;

	if (ft_arrsize(line) != 6 || !ft_isnum(line[3]) || !ft_isnum(line[4]))
		return (ERROR);
	parsed.cy.diameter = ft_atod(line[3]);
	parsed.cy.hei = ft_atod(line[4]);
	return (parse_split(&(parsed.cy.pos), line[1]) && \
			parse_split(&(parsed.cy.n), line[2]) && \
			parse_split(&(parsed.cy.color), line[5]) && \
			parsed_list_add(box, cy, parsed));
}
