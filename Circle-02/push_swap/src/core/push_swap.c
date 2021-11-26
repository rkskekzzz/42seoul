/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:27:23 by suhshin           #+#    #+#             */
/*   Updated: 2021/09/27 21:41:46 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rewind_stack(int ra_cnt, int rb_cnt)
{
	int	min;
	int	i;

	i = -1;
	min = ra_cnt;
	if (ra_cnt > rb_cnt)
		min = rb_cnt;
	while (++i < min)
		rrr();
	while (--ra_cnt >= min)
		rra();
	while (--rb_cnt >= min)
		rrb();
	return (TRUE);
}

t_bool	already_sort(int type, int size)
{
	t_list	*tmp;
	int		dir;
	int		idx;

	idx = -1;
	dir = ht()->stack[type]->val;
	tmp = ht()->stack[type]->link[dir]->link[dir];
	while (++idx < size - 1)
	{
		if ((type == AHEAD) && tmp->val < tmp->link[!dir]->val)
			return (FALSE);
		else if ((type == BHEAD) && tmp->val > tmp->link[!dir]->val)
			return (FALSE);
		tmp = tmp->link[dir];
	}
	if (type == BHEAD)
		while (--size >= 0)
			pa();
	return (TRUE);
}

int	a_to_b(int size)
{
	int	*pivot;
	int	cnt[12];

	ps_memset(cnt, 0, sizeof(int) * 12);
	if (size <= 2)
		under_2_a(size);
	else if (!already_sort(AHEAD, size))
	{
		pivot = find_pivot(AHEAD, size);
		while (--size >= 0)
		{
			if (ht()->stack[AHEAD]->link[HEAD]->val >= pivot[BIG])
				cnt[PA] += ra();
			else
			{
				cnt[PB] += pb();
				if (ht()->stack[BHEAD]->link[HEAD]->val >= pivot[SMALL])
					cnt[RB] += rb();
			}
		}
		free(pivot);
		rewind_stack(cnt[PA], cnt[RB]);
		a_to_b(cnt[PA]);
		b_to_a(cnt[RB]);
		b_to_a(cnt[PB] - cnt[RB]);
	}
	return (TRUE);
}

int	b_to_a(int size)
{
	int	*pivot;
	int	cnt[12];

	ps_memset(cnt, 0, sizeof(int) * 12);
	if (size <= 2)
		under_2_b(size);
	else if (!already_sort(BHEAD, size))
	{
		pivot = find_pivot(BHEAD, size);
		while (--size >= 0)
		{
			if (ht()->stack[BHEAD]->link[HEAD]->val < pivot[SMALL])
				cnt[RB] += rb();
			else
			{
				cnt[PA] += pa();
				if (ht()->stack[AHEAD]->link[HEAD]->val < pivot[BIG])
					cnt[RA] += ra();
			}
		}
		free(pivot);
		a_to_b(cnt[PA] - cnt[RA]) && rewind_stack(cnt[RA], cnt[RB]);
		a_to_b(cnt[RA]) && b_to_a(cnt[RB]);
	}
	return (TRUE);
}
