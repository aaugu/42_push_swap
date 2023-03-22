/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:12:59 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/22 18:37:43 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_bool	is_same_pos(int pos_a, int pos_b, int size_a, int size_b);

// Get costs of moving of every number in A to the good position in B.
int	*get_costs(t_stack *a, t_stack *b)
{
	int	*costs;
	int	cost_a;
	int	cost_b;
	int	pos_b;
	int	i;

	costs = (int *)ft_calloc(sizeof(int), (a->size + b->size));
	if (!costs)
		return (0);
	i = 0;
	while (i < a->size)
	{
		cost_a = cost_move_top(a, i);
		pos_b = get_pos_b(b, a->stack[i]);
		cost_b = cost_move_top(b, pos_b);
		if (is_same_pos == TRUE)
			costs[i] = cost_a;
		else
			costs[i] = cost_a + cost_b;
		i++;
	}
	return (costs);
}

// Check if pos to move in A and B are at same pos from begin or end of A and B
t_bool	is_same_pos(int pos_a, int pos_b, int size_a, int size_b)
{
	if ((pos_a > (size_a - 1) / 2 && (pos_b > (size_b - 1) / 2))
		&& (size_a - 1 - pos_a == size_b - 1 - pos_b))
		return (1);
	else if ((pos_a <= (size_a - 1) / 2 && (pos_b <= (size_b - 1) / 2))
		&& pos_a == pos_b)
		return (1);
	return (0);
}

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
	else
		return (0);
}
