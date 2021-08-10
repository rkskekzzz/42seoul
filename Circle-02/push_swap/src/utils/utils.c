#include "push_swap.h"

t_bool	prt_error(char *message)
{
	return (printf("%s\n", message) >= 0);
}

void 	ps_freend(void **ptr)
{
	free(*ptr);
	*ptr = 0;
}

t_bool	prt_func(int val)
{
	val == SA && printf("sa\n");
	val == SB && printf("sb\n");
	val == SS && printf("sS\n");
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
