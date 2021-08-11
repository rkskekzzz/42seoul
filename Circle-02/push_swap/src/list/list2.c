/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:28:07 by suhshin           #+#    #+#             */
/*   Updated: 2021/08/11 20:28:08 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prt_list(int t)
{
	t_list	*tmp;
	int		dir;

	if (ht()->size[t >> 1] == 0)
		return ;
	dir = ht()->stack[t]->val;
	tmp = ht()->stack[t]->link[dir];
	while (tmp->link[dir])
	{
		(t != FHEAD) && printf("%d ", tmp->val);
		(t == FHEAD) && prt_func(tmp->val);
		tmp = tmp->link[dir];
	}
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
	ps_free((void *)&ht()->stack[t & 2]);
	ps_free((void *)&ht()->stack[(t & 2) + 1]);
}
