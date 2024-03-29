/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:27:34 by suhshin           #+#    #+#             */
/*   Updated: 2021/09/27 21:43:23 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(int **list, int left, int right)
{
	int	key;
	int	i;
	int	j;

	if (left >= right)
		return ;
	key = left;
	i = left + 1;
	j = right;
	while (i <= j)
	{
		while (i <= right && (*list)[i] <= (*list)[key])
			++i;
		while (j > left && (*list)[j] >= (*list)[key])
			--j;
		if (i > j)
			ps_swap(&((*list)[key]), &((*list)[j]));
		else
			ps_swap(&((*list)[i]), &((*list)[j]));
	}
	quick_sort(list, left, j - 1);
	quick_sort(list, j + 1, right);
}

int	*find_pivot(int t, int size)
{
	int		*arr;
	int		*out;
	int		idx;
	t_list	*tmp;

	idx = -1;
	tmp = ht()->stack[t]->link[ht()->stack[t]->val];
	out = malloc(sizeof(int) * 2);
	arr = malloc(sizeof(int) * size);
	if (!out || !arr)
		exit(1);
	while (++idx < size)
	{
		arr[idx] = tmp->val;
		tmp = tmp->link[ht()->stack[t]->val];
	}
	quick_sort(&arr, 0, size - 1);
	out[0] = arr[size / 3];
	out[1] = arr[size * 2 / 3];
	ps_free((void *)&arr);
	return (out);
}

int	find_border(void)
{
	int		*arr;
	int		idx;
	t_list	*tmp;

	idx = -1;
	tmp = ht()->stack[AHEAD]->link[HEAD];
	arr = malloc(sizeof(int) * 5);
	if (!arr)
		exit(1);
	while (++idx < 5)
	{
		arr[idx] = tmp->val;
		tmp = tmp->link[HEAD];
	}
	quick_sort(&arr, 0, 4);
	return (arr[1]);
}
