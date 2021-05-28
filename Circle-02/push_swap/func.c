#include "push_swap.h"

t_ht	*ht(void)
{
	static t_ht	*ht;

	return (ht);
}

void sa()
{
	swap_list(ht()->b_head);
}

void sb()
{
	swap_list(ht()->b_head);
}

void ss()
{
	sa();
	sb();
}

void pa()
{
	add_list(ht()->a_head, del_list(ht()->b_head, ht()->b_size));
}

void pa()
{
	add_list(ht()->b_head, del_list(ht()->a_head, ht()->a_size));
}

void rr()
{
	(ra && rb);
}

void ra()
{
	add_list(ht()->a_tail, del_list(ht()->a_head, ht()->a_size));
}

void rb()
{
	add_list(ht()->b_tail, del_list(ht()->b_head, ht()->b_size));
}

void rrr()
{
	(rra && rrb);
}

void rra()
{
	add_list(ht()->a_head, del_list(ht()->a_tail, ht()->a_size));
}

void rrb()
{
	add_list(ht()->b_head, del_list(ht()->b_tail, ht()->b_size));
}

// swap_list(ht()->b_head);
cmd[0] = (*rtptr(swap_list))(ht()->b_head);

void (*rtptr(void *))(void)
{
	if void* == swap_list
		return swap_list;

}
