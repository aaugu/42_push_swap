/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:12:59 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/23 23:46:58 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		cost_move_top(t_stack *stack, int pos);

int	*get_costs(t_stack *a, t_stack *b)
{
	int	*costs;
	int	cost_a;
	int	cost_b;
	int	pos_b;
	int	i;

	costs = (int *)ft_calloc(sizeof(int), a->size);
	if (!costs)
		return (0);
	i = 0;
	while (i < a->size)
	{
		cost_a = cost_move_top(a, i);
		pos_b = get_pos_b(b, a->stack[i]);
		cost_b = cost_move_top(b, pos_b);
		if (is_same_pos(i, pos_b, a->size, b->size) == TRUE)
			costs[i] = cost_a;
		else
			costs[i] = cost_a + cost_b;
		i++;
	}
	return (costs);
}

int	cost_move_top(t_stack *stack, int pos)
{

	if (is_at_begin(pos, stack->size) == TRUE)
		return (pos);
	else
		return (stack->size - pos);
}
