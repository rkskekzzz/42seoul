#include "push_swap.h"

int	init_stack(t_list **tail, t_list **head)
{
	t_list	*new_head;
	t_list	*new_tail;

	new_head = ft_lstnew(42);
	new_tail = ft_lstnew(42);
	if (!new_head || !new_tail)
		return (ERROR);
	new_head->link[0] = new_tail;
	new_tail->link[1] = new_head;
	new_head->val = HEAD;
	new_tail->val = TAIL;
	*head = new_head;
	*tail = new_tail;
	return (OK);
}

int	add_list(t_list *pos, int val)
{
	t_list	*new_node;
	t_list	*tmp;

	tmp = pos;
	pos = pos->link[tmp->val];
	new_node = ft_lstnew(val);
	if (!new_node)
		return (ERROR);
	new_node->link[!tmp->val] = tmp;
	new_node->link[tmp->val] = tmp->link[tmp->val];
	tmp->link[tmp->val]->link[!tmp->val] = new_node;
	tmp->link[tmp->val] = new_node;
	new_node->val = val;
	return (OK);
}

int		del_list(t_list *list, int size)
{
	int del;

	if (size == 0)
		return 0;
	del = list->val;
	list->link[1]->link[0] = list->link[0];
	list->link[0]->link[1] = list->link[1];
	freend(&list->link[0]);
	freend(&list->link[1]);
	freend(&list);
	return (del);
}

void	swap_list(t_list *list)
{
	int	tmp;

	if (!list->link[list->val]->link[list->val]->link[list->val])
		return ;
	tmp = list->link[list->val]->val;
	list->link[list->val]->val = list->link[list->val]->link[list->val]->val;
	list->link[list->val]->link[list->val]->val = tmp;
}

int	size_list(t_list *tail, t_list *head)
{
	int		cnt;
	t_list	*tmp;

	cnt = 0;
	tmp = tail;
	while (tmp && tmp->link[1] != head)
	{
		tmp = tmp->link[1];
		++cnt;
	}
	return (cnt);
}

int search_list(t_list *tail, t_list *head, int find)
{
	t_list *tmp;

	tmp = tail;
	while (tmp != head)
	{
		if (tmp->val == find)
			return (1);
		tmp = tmp->link[1];
	}
	return (0);
}

void print_list(t_list *tail, t_list *head)
{
	t_list *tmp;

	tmp = tail->link[1];
	while (tmp != head)
	{
		printf("%d ", tmp->val);
		tmp = tmp->link[1];
	}
	printf("\n");
}

t_list	*ft_lstnew(int val)
{
	t_list	*new_node;

	if (!(new_node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new_node->val = val;
	new_node->link[0] = NULL;
	new_node->link[1] = NULL;
	return (new_node);
}
