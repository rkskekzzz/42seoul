#include "push_swap.h"

char	*join_argv(char **argv)
{
	char	*ret;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = -1;
	ret = malloc(BUFFER_SIZE);
	if (!ret)
		return (NULL);
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			ret[++k] = argv[i][j];
		}
		ret[++k] = ' ';
	}
	ret[++k] = 0;
	return (ret);
}

void	init(char **argv)
{
	int	idx;

	init_stack(&(ht()->stack[ATAIL]), &(ht()->stack[AHEAD]));
	init_stack(&(ht()->stack[BTAIL]), &(ht()->stack[BHEAD]));
	init_stack(&(ht()->stack[FTAIL]), &(ht()->stack[FHEAD]));
	ht()->size[A] = 0;
	ht()->size[B] = 0;
	ht()->size[F] = 0;
	idx = -1;
	while (argv[++idx])
		add_list(ATAIL, ps_isnum_atoi(argv[idx]));
}

void	parsing(char ***argv)
{
	char	*str;

	str = join_argv(*argv);
	if (!str)
		exit(prt_error("parse ERROR\n"));
	*argv = ps_split(str, " \"\'");
	free(str);
}

void	solution(void)
{
	if (ht()->size[A] == 3)
		size_3_a();
	else if (ht()->size[A] == 5)
		size_5_a();
	else
		a_to_b(ht()->size[A]);
}

void	push_swap(char **argv)
{
	parsing(&argv);
	init(argv);
	solution();
	prt_list(FHEAD);
	ps_free_split(argv);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		push_swap(argv);
	else
		prt_error("Arguments Error!\n");	;
	return (0);
}
