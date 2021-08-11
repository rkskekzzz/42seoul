/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:27:50 by suhshin           #+#    #+#             */
/*   Updated: 2021/08/11 20:27:51 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (ht()->size[F] > 1 && ht()->stack[FTAIL]->link[TAIL]->val == SB)
	{
		ht()->stack[FTAIL]->link[TAIL]->val = SS;
		return (TRUE);
	}
	return (add_list(FTAIL, SA));
}

t_bool	sb(void)
{
	if (!swp_list(BHEAD))
		return (FALSE);
	if (ht()->size[F] > 1 && ht()->stack[FTAIL]->link[TAIL]->val == SA)
	{
		ht()->stack[FTAIL]->link[TAIL]->val = SS;
		return (TRUE);
	}
	return (add_list(FTAIL, SB));
}

t_bool	ss(void)
{
	if (!swp_list(AHEAD) || !swp_list(BHEAD))
		return (FALSE);
	return (add_list(FTAIL, SS));
}
