#include "push_swap.h"

t_ht	*ht(void)
{
	static t_ht	ht;

	return (&ht);
}

t_bool	sa(void)
{
	if (!swp_list(AHEAD))
		return (FALSE);
	printf("sa\n");
	return (TRUE);
}

t_bool	sb(void)
{
	if (!swp_list(BHEAD))
		return (FALSE);
	printf("sb\n");
	return (TRUE);
}

t_bool	ss(void)
{
	if (!swp_list(AHEAD) || !swp_list(BHEAD))
		return (FALSE);
	printf("ss\n");
	return (TRUE);
}

t_bool	pa(void)
{
	if (!add_list(AHEAD, del_list(BHEAD)))
		return (FALSE);
	printf("pa\n");
	return (TRUE);
}

t_bool	pb(void)
{
	if (!add_list(BHEAD, del_list(AHEAD)))
		return (FALSE);
	printf("pb\n");
	return (TRUE);
}

t_bool	ra(void)
{
	if (!add_list(ATAIL, del_list(AHEAD)))
		return (FALSE);
	printf("ra\n");
	return (TRUE);
}

t_bool	rb(void)
{
	if (!add_list(BTAIL, del_list(BHEAD)))
		return (FALSE);
	printf("rb\n");
	return (TRUE);
}

t_bool	rr(void)
{
	if (!add_list(ATAIL, del_list(AHEAD)) || \
		!add_list(BTAIL, del_list(BHEAD)))
		return (FALSE);
	printf("rr\n");
	return (TRUE);
}

t_bool	rra(void)
{
	if (!add_list(AHEAD, del_list(ATAIL)))
		return (FALSE);
	printf("rra\n");
	return (TRUE);
}

t_bool	rrb(void)
{
	if (!add_list(BHEAD, del_list(BTAIL)))
		return (FALSE);
	printf("rrb\n");
	return (TRUE);
}

t_bool	rrr(void)
{
	if (!add_list(AHEAD, del_list(ATAIL)) || \
		!add_list(BHEAD, del_list(BTAIL)))
		return (FALSE);
	printf("rrr\n");
	return (TRUE);
}
