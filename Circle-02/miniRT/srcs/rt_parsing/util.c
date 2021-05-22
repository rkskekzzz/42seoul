/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 18:01:55 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/22 18:02:05 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	printf_ok(char *s)
{
	printf("%s\n", s);
	return (OK);
}

int	printf_error(char *s)
{
	printf("%s Error!\n", s);
	exit(1);
	return (ERROR);
}

int	parse_split(t_vec *input, char *line)
{
	char **tmp;

	tmp = ft_split(line, ",");
	if (ft_arrsize(tmp) != 3 || \
		!ft_atod(&input->x, tmp[0]) || \
		!ft_atod(&input->y, tmp[1]) || \
		!ft_atod(&input->z, tmp[2]))
		return (ERROR);
	ft_free_split(tmp, ft_arrsize(tmp));
	return (OK);
}
