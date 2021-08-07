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

void	a_to_b(int size)
{
	int	*pivot;
	int	ra_cnt;
	int	pb_cnt;
	int	rb_cnt;

	ra_cnt = 0;
	rb_cnt = 0;
	pb_cnt = 0;
	if (size <= 3)
		under_3_a(size);
	else
	{
		pivot = find_pivot(AHEAD, size);
		// printf("pivot : %d, %d\n", pivot[0], pivot[1]);
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
		// printf("**************1************** %d\n", 42);
		rewind_stack(ra_cnt, rb_cnt);
		// printf("**************2************** %d\n", ra_cnt);
		a_to_b(ra_cnt);
		// printf("**************3************** %d\n", rb_cnt);
		b_to_a(rb_cnt);
		// printf("**************4************** %d\n", pb_cnt - rb_cnt);
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
	if (size <= 3)
		under_3_b(size);
	else
	{
		pivot = find_pivot(BHEAD, size);
		//printf("pivot : %d, %d\n", pivot[0], pivot[1]);
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
		// printf("--------------1-------------- %d\n", pa_cnt - ra_cnt);
		a_to_b(pa_cnt - ra_cnt);
		// printf("--------------2-------------- %d\n", 42);
		rewind_stack(ra_cnt, rb_cnt);
		// printf("--------------3-------------- %d\n", ra_cnt);
		a_to_b(ra_cnt);
		// printf("--------------4-------------- %d\n", rb_cnt);
		b_to_a(rb_cnt);
	}
}
