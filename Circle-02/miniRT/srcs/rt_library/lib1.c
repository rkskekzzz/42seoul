/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:07:26 by suhshin           #+#    #+#             */
/*   Updated: 2021/05/22 17:08:23 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

double	clamp(double n, double min, double max)
{
	if (n < min)
		return (min);
	if (n > max)
		return (max);
	return (n);
}

double	ft_abs(double n)
{
	if (0 > n)
		return (-n);
	return (n);
}

double	ft_min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

double	ft_max(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}
