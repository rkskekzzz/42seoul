#include "push_swap.h"

t_case	case_3(int type)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;
	int		dir;

	dir = ht()->stack[type]->val;
	a = ht()->stack[type]->link[dir];
	b = a->link[dir];
	c = b->link[dir];
	if (b->val > a->val && c->val > b->val && c->val > a->val)
		return (case_123);
	else if (b->val > a->val && b->val > c->val && c->val > a->val)
		return (case_132);
	else if (a->val > b->val && c->val > b->val && c->val > a->val)
		return (case_213);
	else if (b->val > a->val && b->val > c->val && a->val > c->val)
		return (case_231);
	else if (a->val > b->val && a->val > c->val && c->val > b->val)
		return (case_312);
	else if (a->val > b->val && a->val > c->val && b->val > c->val)
		return (case_321);
	return (FALSE);
}

void	size_3_a(void)
{
	t_case	c;

	c = case_3(AHEAD);
	if (c == case_123)
		return ;
	else if (c == case_132)
		ra() && sa() && rra();
	else if (c == case_213)
		sa();
	else if (c == case_231)
		ra() && sa() && rra() && sa();
	else if (c == case_312)
		sa() && ra() && sa() && rra();
	else if (c == case_321)
		pb() && ra() && pa() && sa() && rra() && sa();
}

void	size_3_b(void)
{
	t_case	c;

	c = case_3(BHEAD);
	if (c == case_123)
		pa() && ra() && sb() && pa() && pa() && rra();
	else if (c == case_132)
		sb() && pa() && sb() && pa() && pa();
	else if (c == case_213)
		pa() && sb() && pa() && sa() && pa();
	else if (c == case_231)
		sb() && pa() && pa() && pa();
	else if (c == case_312)
		pa() && pa() && pa() && sa();
	else if (c == case_321)
		pa() && pa() && pa();
}

void	under_3_a(int size)
{
	if (size == 2 && \
		ht()->stack[AHEAD]->link[HEAD]->val > \
		ht()->stack[AHEAD]->link[HEAD]->link[HEAD]->val)
		sa();
	else if (size == 3)
		size_3_a();
}

void	under_3_b(int size)
{
	if (size <= 1)
		pa();
	else if (size == 2)
	{
		if (ht()->stack[BHEAD]->link[HEAD]->val < \
			ht()->stack[BHEAD]->link[HEAD]->link[HEAD]->val)
			sb();
		pa();
		pa();
	}
	else if (size == 3)
		size_3_b();
}
