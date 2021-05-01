#include "parse.h"

int	parse_r(char **line, t_box *box)
{
	if (!box->parsed[r].next || \
		ft_arrsize(line) != 3 || \
		!ft_isnum(line[1]) || \
		!ft_isnum(line[2]))
		return (ERROR);
	box->parsed[r].id.r.wid = ft_atoi(line[1]);
	box->parsed[r].id.r.hei = ft_atoi(line[2]);
	box->parsed[r].next = 1;
	return (OK);
}

int	parse_sp(char **line, t_box *box)
{
	t_parsed	parsed;

	if (ft_arrsize(line) != 4 || !ft_isnum(line[2]))
		return (ERROR);
	parsed.sp.diameter = ft_atoi(line[2]);
	return (parse_split(&(parsed.sp.pos), line[1]) && \
			parse_split(&(parsed.sp.color), line[3]) && \
			parsed_list_add(box, sp, parsed));
}

int	parse_sq(char **line, t_box *box)
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

int	parse_tr(char **line, t_box *box)
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
