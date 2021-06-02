#include "push_swap.h"

void	init_stack(t_list **tail, t_list **head)
{
	t_list	*new_head;
	t_list	*new_tail;

	new_head = new_list(HEAD);
	new_tail = new_list(TAIL);
	if (!new_head || !new_tail)	// free 해주기
		exit(prt_error("Malloc Error!"));
	new_head->link[HEAD] = new_tail;
	new_tail->link[TAIL] = new_head;
	*head = new_head;
	*tail = new_tail;
}

int	add_list(int t, int val)
{
	t_list	*new_node;
	t_list	*tmp;

	tmp = ht()->stack[t];
	new_node = new_list(val);
	if (!new_node)
		return (ERROR);
	new_node->link[!tmp->val] = tmp;
	new_node->link[tmp->val] = tmp->link[tmp->val];
	tmp->link[tmp->val]->link[!tmp->val] = new_node;
	tmp->link[tmp->val] = new_node;
	++ht()->size[t >> 1];
	return (OK);
}

int	del_list(int t)
{
	int		ret;
	t_list	*pos;

	if (!ht()->size[t >> 1])
		return (0);
	pos = ht()->stack[t]->link[ht()->stack[t]->val];
	ret = pos->val;
	pos->link[1]->link[0] = pos->link[0];
	pos->link[0]->link[1] = pos->link[1];
	ps_freend((void *)&pos);
	--ht()->size[t >> 1];
	return (ret);
}

int	swp_list(int t)
{
	int		tmp;
	t_list	*pos;

	if (ht()->size[t >> 1] < 2)
		return (ERROR);
	pos = ht()->stack[t];
	tmp = pos->link[pos->val]->val;
	pos->link[pos->val]->val = pos->link[pos->val]->link[pos->val]->val;
	pos->link[pos->val]->link[pos->val]->val = tmp;
	return (OK);
}

int srh_list(int t, int find)
{
	t_list *tmp;

	tmp = ht()->stack[t]->link[ht()->stack[t]->val];
	while (tmp->link[ht()->stack[t]->val])
	{
		if (tmp->val == find)
			return (1);
		tmp = tmp->link[ht()->stack[t]->val];
	}
	return (0);
}

void prt_list(int t)
{
	t_list *tmp;

	tmp = ht()->stack[t]->link[ht()->stack[t]->val];
	while (tmp->link[ht()->stack[t]->val])
	{
		printf("%d ", tmp->val);
		tmp = tmp->link[ht()->stack[t]->val];
	}
	printf("\n");
}
