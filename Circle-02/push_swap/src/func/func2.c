#include "push_swap.h"

t_bool	pa(void)
{
	if (!add_list(AHEAD, del_list(BHEAD)))
		return (FALSE);
	return (add_list(FTAIL, PA));
}

t_bool	pb(void)
{
	if (!add_list(BHEAD, del_list(AHEAD)))
		return (FALSE);
	return (add_list(FTAIL, PB));
}

t_bool	ra(void)
{
	if (!add_list(ATAIL, del_list(AHEAD)))
		return (FALSE);
	if (ht()->stack[FTAIL]->link[TAIL]->val == RB)
	{
		ht()->stack[FTAIL]->link[TAIL]->val = RR;
		return (TRUE);
	}
	return (add_list(FTAIL, RA));
}

t_bool	rb(void)
{
	if (!add_list(BTAIL, del_list(BHEAD)))
		return (FALSE);
	if (ht()->stack[FTAIL]->link[TAIL]->val == RA)
	{
		ht()->stack[FTAIL]->link[TAIL]->val = RR;
		return (TRUE);
	}
	return (add_list(FTAIL, RB));
}

t_bool	rr(void)
{
	if (!add_list(ATAIL, del_list(AHEAD)) || \
		!add_list(BTAIL, del_list(BHEAD)))
		return (FALSE);
	return (add_list(FTAIL, RR));
}
