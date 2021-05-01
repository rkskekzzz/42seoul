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
