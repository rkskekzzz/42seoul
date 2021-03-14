/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 09:17:24 by suhshin           #+#    #+#             */
/*   Updated: 2021/01/02 09:57:47 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	if (!(new_node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
