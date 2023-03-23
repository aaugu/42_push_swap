/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:12:59 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/23 15:18:23 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		cost_move_top(t_stack *stack, int pos);
void	move_top_both(t_stack *a, t_stack *b);
void	move_top_one(t_stack *stack, char pile);
void	change_pos(t_stack *stack, int instruction);

// Get costs of moving of every number in A to the good position in B.
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

void	moves_top(t_stack *a, t_stack *b)
{
	while (b->pos != 0)
	{
		if (is_same_pos(a->pos, b->pos, a->size, b->size) == TRUE)
			move_top_both(a, b);
		else
			move_top_one(b, 'b');
	}
	while (a->pos != 0)
		move_top_one(a, 'a');
}

void	move_top_both(t_stack *a, t_stack *b)
{
	if ((is_at_begin(a->pos, a->size) && is_at_begin(b->pos, b->size)) \
		|| (a->pos == 1 && b->pos == 1))
	{
		rotate(a, NULL);
		rotate(b, "rr");
		change_pos(a, 0);
		change_pos(b, 0);
	}
	else
	{
		reverse_rotate(a, NULL);
		reverse_rotate(b, "rrr");
		change_pos(a, 1);
		change_pos(b, 1);
	}
}

void	move_top_one(t_stack *stack, char pile)
{
	if (is_at_begin(stack->pos, stack->size))
	{
		if (pile == 'a')
			rotate(stack, "ra");
		else
			rotate(stack, "rb");
		change_pos(stack, 0);
	}
	else
	{
		if (pile == 'a')
			reverse_rotate(stack, "rra");
		else
			reverse_rotate(stack, "rrb");
		change_pos(stack, 1);
	}
}
