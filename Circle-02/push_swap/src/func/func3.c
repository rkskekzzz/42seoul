#include "push_swap.h"

t_bool	rra(void)
{
	if (!add_list(AHEAD, del_list(ATAIL)))
		return (FALSE);
	if (ht()->stack[FTAIL]->link[TAIL]->val == RRB)
	{
		ht()->stack[FTAIL]->link[TAIL]->val = RRR;
		return (TRUE);
	}
	return (add_list(FTAIL, RRA));
}

t_bool	rrb(void)
{
	if (!add_list(BHEAD, del_list(BTAIL)))
		return (FALSE);
	if (ht()->stack[FTAIL]->link[TAIL]->val == RRA)
	{
		ht()->stack[FTAIL]->link[TAIL]->val = RRR;
		return (TRUE);
	}
	return (add_list(FTAIL, RRB));
}

t_bool	rrr(void)
{
	if (!add_list(AHEAD, del_list(ATAIL)) || \
		!add_list(BHEAD, del_list(BTAIL)))
		return (FALSE);
	return (add_list(FTAIL, RRR));
}
