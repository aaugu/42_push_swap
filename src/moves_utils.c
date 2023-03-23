/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:55:18 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/23 21:55:48 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void move_top_both(t_stack *a, t_stack *b);

void	move_pos_top(t_stack *a, t_stack *b)
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

void move_top_both(t_stack *a, t_stack *b)
{
	if ((is_at_begin(a->pos, a->size) && is_at_begin(b->pos, b->size)) || (a->pos == 1 && b->pos == 1))
	{
		rotate(a, NULL);
		rotate(b, "rr");
		change_pos(a, "r");
		change_pos(b, "r");
	}
	else
	{
		reverse_rotate(a, NULL);
		reverse_rotate(b, "rrr");
		change_pos(a, "rr");
		change_pos(b, "rr");
	}
}

void move_top_one(t_stack *stack, char pile)
{
	if (is_at_begin(stack->pos, stack->size))
	{
		if (pile == 'a')
			rotate(stack, "ra");
		else
			rotate(stack, "rb");
		change_pos(stack, "r");
	}
	else
	{
		if (pile == 'a')
			reverse_rotate(stack, "rra");
		else
			reverse_rotate(stack, "rrb");
		change_pos(stack, "rr");
	}
}
