#include "push_swap.h"

void	init_stack(t_list **tail, t_list **head)
{
	t_list	*new_head;
	t_list	*new_tail;

	new_head = new_list(HEAD);
	new_tail = new_list(TAIL);
	if (!new_head || !new_tail)
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
		return (FALSE);
	new_node->link[!tmp->val] = tmp;
	new_node->link[tmp->val] = tmp->link[tmp->val];
	tmp->link[tmp->val]->link[!tmp->val] = new_node;
	tmp->link[tmp->val] = new_node;
	++ht()->size[t >> 1];
	return (TRUE);
}

int	del_list(int t)
{
	int		ret;
	t_list	*pos;

	if (!ht()->size[t >> 1])
		return (0);
	pos = ht()->stack[t]->link[ht()->stack[t]->val];
	ret = pos->val;
	pos->link[HEAD]->link[TAIL] = pos->link[TAIL];
	pos->link[TAIL]->link[HEAD] = pos->link[HEAD];
	ps_freend((void *)&pos);
	--ht()->size[t >> 1];
	return (ret);
}

int	swp_list(int t)
{
	int		tmp;
	t_list	*pos;

	if (ht()->size[t >> 1] < 2)
		return (FALSE);
	pos = ht()->stack[t];
	tmp = pos->link[pos->val]->val;
	pos->link[pos->val]->val = pos->link[pos->val]->link[pos->val]->val;
	pos->link[pos->val]->link[pos->val]->val = tmp;
	return (TRUE);
}

int	srh_list(int t, int find)
{
	t_list	*tmp;
	int		dir;

	dir = ht()->stack[t]->val;
	tmp = ht()->stack[t]->link[dir];
	while (tmp->link[dir])
	{
		if (tmp->val == find)
			return (TRUE);
		tmp = tmp->link[dir];
	}
	return (FALSE);
}



void	prt_list(int t)
{
	t_list	*tmp;
	int		dir;

	dir = ht()->stack[t]->val;
	tmp = ht()->stack[t]->link[dir];
	printf("-> ");
	while (tmp->link[dir])
	{
		(t != FHEAD) && printf("%d ", tmp->val);
		(t == FHEAD) && prt_func(tmp->val);
		tmp = tmp->link[dir];
	}
	printf("\n");
}

t_list	*new_list(int val)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->val = val;
	new_node->link[0] = NULL;
	new_node->link[1] = NULL;
	return (new_node);
}

void	free_list(int t)
{
	while (ht()->size[t >> 1])
		del_list(t);
	ps_freend((void *)&ht()->stack[t & 2]);
	ps_freend((void *)&ht()->stack[(t & 2) + 1]);
}
