/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:12:59 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/29 14:01:50 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_bool	is_at_begin(int pos, int size);
int		final_cost(int cost_a, int cost_b);
int		absolute_value(int nb);

int	*get_costs(t_stack *a, t_stack *b)
{
	int	*costs;
	int	cost_a;
	int	cost_b;
	int	i;

	costs = (int *)ft_calloc(sizeof(int), b->size);
	if (!costs)
		return (0);
	i = 0;
	while (i < b->size)
	{
		cost_b = cost_move_top(b, i);
		a->pos = get_pos_a(a, b, i);
		cost_a = cost_move_top(a, a->pos);
		costs[i] = final_cost(cost_a, cost_b);
		i++;
	}
	return (costs);
}

int	cost_move_top(t_stack *stack, int pos)
{
	if (is_at_begin(pos, stack->size) == TRUE)
	{
		return (pos);
	}
	else
	{
		return (pos - stack->size);
	}
}

int	final_cost(int cost_a, int cost_b)
{
	if (cost_a == cost_b)
		return (absolute_value(cost_a));
	else if ((cost_a < 0 && cost_b < 0) || (cost_a > 0 && cost_b > 0))
	{
		if (cost_a < cost_b && (cost_a < 0 && cost_b < 0))
			return (absolute_value(cost_b));
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

t_bool	is_at_begin(int pos, int size)
{
	if ((pos <= size / 2))
		return (1);
	return (0);
}
