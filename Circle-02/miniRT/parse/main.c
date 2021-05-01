#include "main.h"
#include "parse.h"

int	printf_error(void)
{
	printf("parsing error\n");
	return (ERROR);
}

int		parsing(char *file, t_box *box)
{
	char ch[1];
	int	s;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	s = ft_strlen(file);
	if (fd < 0 || s < 3 || file[s - 1] != 't' || file[s - 2] != 'r' || file[s - 3] != '.')
		return (ERROR);
	s = read(fd, &ch, 1);
	while (s)
	{
		box->line[i++] = ch[0];
		s = read(fd, &ch, 1);
	}
	return (s);
}

int parse_split(t_vec *input, char *line)
{
	char **tmp;

	tmp = ft_split(line, ",");
	if (ft_arrsize(tmp) != 3 ||!ft_isnum(tmp[0]) || !ft_isnum(tmp[1]) || !ft_isnum(tmp[2]))
		return (ERROR);
	input->x = ft_atod(tmp[0]);
	input->y = ft_atod(tmp[1]);
	input->z = ft_atod(tmp[2]);
	ft_free_split(tmp, ft_arrsize(tmp));
	return (OK);
}

void parser_init(int (*parser[9])(char **, t_box *))
{
	parser[r] = parse_r;
	parser[a] = parse_a;
	parser[c] = parse_c;
	parser[l] = parse_l;
	parser[sp] = parse_sp;
	parser[pl] = parse_pl;
	parser[sq] = parse_sq;
	parser[cy] = parse_cy;
	parser[tr] = parse_tr;
}

int parsed_list_add(t_box *box, t_parsable index, t_parsed parsed)
{
	t_parsed_list *t;

	t = malloc(sizeof(t_parsed_list));
	if (t == NULL)
		return (ERROR);
	t->id = parsed;
	t->next = box->parsed[index].next;
	box->parsed[index].next = t;
	return (OK);
}

int	parse_all(t_box *box)
{
	int		i;
	int		(*parser[9])(char **, t_box *);
	char	**data;
	char	**line;


	parser_init(parser);
	data = ft_split(box->line, "\n");
	while (*data)
	{
		line = ft_split(*data, WHITESPACE);
		i = -1;
		while (++i < 9)
			if (!ft_strncmp(line[0], \
							(char [9][3]){"R", "A", "c", "l", "sp", "pl" \
										,"sq", "cy", "tr"}[i]) && \
				parser[i](line, box))
				break ;
		if (i == 9)
			return (printf_error());
		ft_free_split(line, ft_arrsize(line));
		++data;
	}
	return (OK);
}

int	main(int argc, char **argv)
{
	t_box	box;

	ft_memset(&box, 0, sizeof(t_box));
	if (argc == 2)
	{
		if (parsing(argv[1], &box) < 0)
			return (0);
		parse_all(&box);
	}
	return (0);
}
