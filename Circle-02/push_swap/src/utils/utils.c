/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:28:31 by suhshin           #+#    #+#             */
/*   Updated: 2021/08/11 20:28:32 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	prt_error(char *message)
{
	return (printf("%s\n", message) >= 0);
}

void	ps_free(void **ptr)
{
	free(*ptr);
	*ptr = 0;
}

t_bool	prt_func(int val)
{
	val == SA && printf("sa\n");
	val == SB && printf("sb\n");
	val == SS && printf("ss\n");
	val == PA && printf("pa\n");
	val == PB && printf("pb\n");
	val == RA && printf("ra\n");
	val == RB && printf("rb\n");
	val == RR && printf("rr\n");
	val == RRA && printf("rra\n");
	val == RRB && printf("rrb\n");
	val == RRR && printf("rrr\n");
	return (TRUE);
}

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
