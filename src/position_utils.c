/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:43:14 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/23 13:02:19 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
Get position of which number in B should be placed on top of B in order to
push number from A to B :
If the number you push is going to be the new max or new min, it should be
placed just above the old max. Else, if number - 1 exists in B, it should be
placed just above number - 1 in B. Else just put it on B.
*/
int	get_pos_b(t_stack *b, int nb_a)
{
	int	i;

	i = 0;
	if (nb_a > b->max || nb_a < b->min)
	{
		while (i < b->size)
		{
			if (b->stack[i] == b->max)
				return (i);
			i++;
		}
	}
	else if (nb_a > b->min && nb_a < b->max)
	{
		while (i < b->size)
		{
			if (b->stack[i] == nb_a - 1)
				return (i);
			i++;
		}
	}
	return (0);
}

t_bool	is_same_pos(int pos_a, int pos_b, int size_a, int size_b)
{
	if ((pos_a == 0 && pos_b == 0) || (pos_a == 1 && pos_b == 1))
		return (1);
	else if (is_at_begin(pos_a, size_a) && is_at_begin(pos_b, size_b) \
		&& pos_a == pos_b)
		return (1);
	else if (!is_at_begin(pos_a, size_a) && !is_at_begin(pos_b, size_b) \
		&& (size_a - pos_a == size_b - pos_b))
		return (1);
	return (0);
}

t_bool	is_at_begin(int pos, int size)
{
	if ((pos <= (size - 1) / 2))
		return (1);
	return (0);
}
