/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:38:52 by su                #+#    #+#             */
/*   Updated: 2021/09/27 18:39:08 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	func(char *str)
{
	if (!ps_strncmp(str, "pa", ps_strlen(str)))
		return (pa());
	if (!ps_strncmp(str, "pb", ps_strlen(str)))
		return (pb());
	if (!ps_strncmp(str, "sa", ps_strlen(str)))
		return (sa());
	if (!ps_strncmp(str, "sb", ps_strlen(str)))
		return (sb());
	if (!ps_strncmp(str, "ss", ps_strlen(str)))
		return (ss());
	if (!ps_strncmp(str, "ra", ps_strlen(str)))
		return (ra());
	if (!ps_strncmp(str, "rb", ps_strlen(str)))
		return (rb());
	if (!ps_strncmp(str, "rr", ps_strlen(str)))
		return (rr());
	if (!ps_strncmp(str, "rra", ps_strlen(str)))
		return (rra());
	if (!ps_strncmp(str, "rrb", ps_strlen(str)))
		return (rrb());
	if (!ps_strncmp(str, "rrr", ps_strlen(str)))
		return (rrr());
	return (0);
}

void	start_sort(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
	{
		func(split[i]);
	}
}
