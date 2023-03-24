/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:12:59 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/24 12:01:40 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	cost_move_top(t_stack *stack, int pos);
int	final_cost(int cost_a, int cost_b);
int	absolute_value(int nb);

int	*get_costs(t_stack *a, t_stack *b)
{
	int	*costs;
	int	cost_a;
	int	cost_b;
	int	i;

	costs = (int *)ft_calloc(sizeof(int), a->size);
	if (!costs)
		return (0);
	i = 0;
	while (i < a->size)
	{
		cost_a = cost_move_top(a, i);
		b->pos = get_pos_b(b, a->stack[i]);
		cost_b = cost_move_top(b, b->pos);
		costs[i] = final_cost(cost_a, cost_b);
		i++;
	}
	return (costs);
}

int	cost_move_top(t_stack *stack, int pos)
{
	if (is_at_begin(pos, stack->size) == TRUE)
		return (pos);
	else
		return (pos - stack->size);
}

int	final_cost(int cost_a, int cost_b)
{
	if ((cost_a < 0 && cost_b < 0) || (cost_a > 0 && cost_b > 0))
	{
		if (cost_a > cost_b)
			return (absolute_value(cost_a));
		else
			return (absolute_value(cost_b));
	}
	else if ((cost_a <= 0 && cost_b >= 0) || (cost_a >= 0 && cost_b <= 0))
	{
		return (absolute_value(cost_a) + absolute_value(cost_b));
	}
	else
		return (0);
}

int	absolute_value(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}
