/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:27:11 by suhshin           #+#    #+#             */
/*   Updated: 2021/09/27 18:46:16 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	{
		if (srh_list(AHEAD, ps_isnum_atoi(argv[idx])))
			exit(prt_error("checker : Same Value Error!"));
		add_list(ATAIL, ps_isnum_atoi(argv[idx]));
	}
}

void	parsing(char ***argv)
{
	char	*str;

	str = join_argv(*argv);
	if (!str)
		exit(prt_error("checker : parse ERROR\n"));
	*argv = ps_split(str, " \"\'");
	free(str);
}

void	solution(void)
{
	char	buf[BUFFER_SIZE];
	char	**split;
	int		read_size;

	read_size = read(STDIN_FILENO, buf, BUFFER_SIZE);
	if (read_size < 0)
		exit(1);
	split = ps_split(buf, "\n");
	start_sort(split);
	ps_free_split(split);
}

void	checker(char **argv)
{
	parsing(&argv);
	init(argv);
	solution();
	if (already_sort(AHEAD, ht()->size[A]))
		printf("OK\n");
	else
		printf("KO\n");
	ps_free_split(argv);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		checker(argv);
	return (0);
}
