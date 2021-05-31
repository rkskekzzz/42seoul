#include "push_swap.h"

t_ht	*ht(void)
{
	static t_ht	ht;

	return (&ht);
}

int	cmd(t_func f)
{
	(f == sa) && swap_list(ht()->stack[AHEAD]) && printf("sa");
	(f == sb) && swap_list(ht()->stack[BHEAD]);
	(f == ss) && cmd(sa) && cmd(sb);
	(f == pa) && add_list(ht()->stack[AHEAD], del_list(BHEAD));
	(f == pb) && add_list(ht()->stack[BHEAD], del_list(AHEAD));
	(f == ra) && add_list(ht()->stack[ATAIL], del_list(AHEAD));
	(f == rb) && add_list(ht()->stack[BTAIL], del_list(BHEAD));
	(f == rr) && cmd(ra) && cmd(rb);
	(f == rra) && add_list(ht()->stack[AHEAD], del_list(ATAIL));
	(f == rrb) && add_list(ht()->stack[BHEAD], del_list(BTAIL));
	(f == rrr) && cmd(rra) && cmd(rrb);
	return (OK);
}

// int	cmds(t_func *f, int n)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < n)
// 		if (!cmd(f[i]))
// 			return (ERROR);
// 	return (OK);
// }

