/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:44:43 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/10 15:06:47 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_lstnb	*lstnew(int nb)
{
	t_lstnb	*lstnew;

	lstnew = (t_lstnb *)malloc(sizeof(t_lstnb));
	if (!lstnew)
		return (0);
	lstnew->nb = nb;
	lstnew->next = NULL;
	return (lstnew);
}

void	lstclear(t_lstnb **lst)
{
	t_lstnb	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(lst);
		*lst = temp;
	}
}
