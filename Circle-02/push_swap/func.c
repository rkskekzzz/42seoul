#include "push_swap.h"

t_ht	*ht(void)
{
	static t_ht	ht;

	return (&ht);
}

int	cmd(t_func f)
{
	(f == sa) && swp_list(AHEAD) && printf("sa\n");
	(f == sb) && swp_list(BHEAD) && printf("sb\n");
	// (f == ss) && cmd(sa) && cmd(sb) && printf("ss\n");
	(f == pa) && add_list(AHEAD, del_list(BHEAD)) && printf("pa\n");
	(f == pb) && add_list(BHEAD, del_list(AHEAD)) && printf("pb\n");
	(f == ra) && add_list(ATAIL, del_list(AHEAD)) && printf("ra\n");
	(f == rb) && add_list(BTAIL, del_list(BHEAD)) && printf("rb\n");
	// (f == rr) && cmd(ra) && cmd(rb) && printf("rr\n");
	(f == rra) && add_list(AHEAD, del_list(ATAIL)) && printf("rra\n");
	(f == rrb) && add_list(BHEAD, del_list(BTAIL)) && printf("rrb\n");
	// (f == rrr) && cmd(rra) && cmd(rrb) && printf("rrr\n");
	return (OK);
}
