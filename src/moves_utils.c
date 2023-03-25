/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:55:18 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/25 01:41:29 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	move_top_both(t_stack *a, t_stack *b);

void	move_pos_top(t_stack *a, t_stack *b)
{
	if ((a->move < 0 && b->move < 0) || (a->move > 0 && b->move > 0))
	{
		while (a->move != 0 || b->move != 0)
		{
			move_top_both(a, b);
			// break ;
		}
	}
	while (a->move != 0)
		move_top_one(a, 'a');
	while (b->move != 0)
		move_top_one(b, 'b');
}

void	move_top_both(t_stack *a, t_stack *b)
{
	if (a->move > 0 && b->move > 0)
	{
		rotate(a, NULL);
		rotate(b, "rr");
		a->move--;
		b->move--;
	}
	else
	{
		reverse_rotate(a, NULL);
		reverse_rotate(b, "rrr");
		a->move++;
		b->move++;
	}
}

void	move_top_one(t_stack *stack, char pile)
{
	if (stack->move > 0)
	{
		if (pile == 'a')
			rotate(stack, "ra");
		else if (pile == 'b')
			rotate(stack, "rb");
		stack->move--;
	}
	else
	{
		if (pile == 'a')
			reverse_rotate(stack, "rra");
		else if (pile == 'b')
			reverse_rotate(stack, "rrb");
		stack->move++;
	}
}
