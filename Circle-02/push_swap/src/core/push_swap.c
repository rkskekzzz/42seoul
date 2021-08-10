#include "push_swap.h"

void 	rewind_stack(int ra_cnt, int rb_cnt)
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
	return (TRUE);
}

void	a_to_b(int size)
{
	int	*pivot;
	int	ra_cnt;
	int	pb_cnt;
	int	rb_cnt;

	ra_cnt = 0;
	rb_cnt = 0;
	pb_cnt = 0;
	if (size <= 2)
		under_2_a(size);
	else if (!already_sort(AHEAD, size))
	{
		pivot = find_pivot(AHEAD, size);
		while (--size >= 0)
		{
			if (ht()->stack[AHEAD]->link[HEAD]->val >= pivot[BIG])
				ra_cnt += ra();
			else
			{
				pb_cnt += pb();
				if (ht()->stack[BHEAD]->link[HEAD]->val >= pivot[SMALL])
					rb_cnt += rb();
			}
		}
		free(pivot);
		rewind_stack(ra_cnt, rb_cnt);
		a_to_b(ra_cnt);
		b_to_a(rb_cnt);
		b_to_a(pb_cnt - rb_cnt);
	}
}

void	b_to_a(int size)
{
	int	*pivot;
	int	ra_cnt;
	int	pa_cnt;
	int	rb_cnt;

	ra_cnt = 0;
	pa_cnt = 0;
	rb_cnt = 0;
	if (size <= 2)
		under_2_b(size);
	else if (!already_sort(BHEAD, size))
	{
		pivot = find_pivot(BHEAD, size);
		while (--size >= 0)
		{
			if (ht()->stack[BHEAD]->link[HEAD]->val < pivot[SMALL])
				rb_cnt += rb();
			else
			{
				pa_cnt += pa();
				if (ht()->stack[AHEAD]->link[HEAD]->val < pivot[BIG])
					ra_cnt += ra();
			}
		}
		free(pivot);
		a_to_b(pa_cnt - ra_cnt);
		rewind_stack(ra_cnt, rb_cnt);
		a_to_b(ra_cnt);
		b_to_a(rb_cnt);
	}
	else
		while (--size >= 0)
			pa();
}
