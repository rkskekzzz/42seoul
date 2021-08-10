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
		rra() && sa();
	else if (c == case_213)
		sa();
	else if (c == case_231)
		rra();
	else if (c == case_312)
		ra();
	else if (c == case_321)
		sa() && rra();
}

void	under_2_a(int size)
{
	if (size == 2 && \
		ht()->stack[AHEAD]->link[HEAD]->val > \
		ht()->stack[AHEAD]->link[HEAD]->link[HEAD]->val)
		sa();
}

void	under_2_b(int size)
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
}

int		find_border(void)
{
	int		*arr;
	int		idx;
	t_list	*tmp;

	idx = -1;
	tmp = ht()->stack[AHEAD]->link[HEAD];
	arr = malloc(sizeof(int) * 5);
	if (!arr)
		exit(1);
	while (++idx < 5)
	{
		arr[idx] = tmp->val;
		tmp = tmp->link[HEAD];
	}
	quick_sort(&arr, 0, 4);
	return (arr[1]);
}

void	size_5_a(void)
{
	int		i;
	int		j;
	int		border;

	i = -1;
	j = -1;
	border = find_border();
	while (++i < 5 && j < 2)
	{
		prt_list(AHEAD);
		prt_list(BHEAD);
		if (ht()->stack[AHEAD]->link[HEAD]->val <= border)
		{
			pb();
			++j;
		}
		else
			ra();
	}
	size_3_a();
	under_2_b(2);
}
