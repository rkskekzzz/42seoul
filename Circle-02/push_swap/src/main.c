#include "push_swap.h"

// ./push_swap 1 3 "3 4 " 5 9 " 10 11"
char*	join_argv(char **argv)
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
	ht()->stack[FUNCL] = new_list(0);
	ht()->size[A] = 0;
	ht()->size[B] = 0;
	idx = -1;
	while (argv[++idx])
		add_list(ATAIL, ps_isnum_atoi(argv[idx]));
}

char	**parsing(char **argv)
{
	char	*str;
	char	**ret;

	str = join_argv(argv);
	if (!str)
		exit(prt_error("parse ERROR\n"));
	ret = ps_split(str, " \"\'");
	free(str);
	return (ret);
}

void	solution(void)
{
	a_to_b(ht()->size[A]);
}

void	push_swap(char **argv)
{
	char	**arr;

	arr = parsing(argv);
	init(arr);
	solution();
	if (DEBUG)
		prt_list(AHEAD);
	ps_free_split(arr);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		push_swap(argv);
	else
		prt_error("Arguments Error!\n");
	return (0);
}
