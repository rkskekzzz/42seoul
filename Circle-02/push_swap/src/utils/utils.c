/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:28:31 by suhshin           #+#    #+#             */
/*   Updated: 2021/08/17 00:58:45 by su               ###   ########.fr       */
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

int	ps_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s2 && n && (*s1 == *s2))
	{
		++s1;
		++s2;
		--n;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
