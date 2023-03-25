/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:59:28 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/25 01:39:57 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

#define PRINT_INT(x) ft_printf("%d\n", x);

int		sort_a(t_stack *a, t_stack *b);
void	empty_b(t_stack *a, t_stack *b);

void	print_stack(t_stack *stack, char *suffix )
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		ft_printf("%d ", stack->stack[i++]);
	}
	if (suffix)
		ft_printf("%s", suffix);
	else
		ft_printf("\n");
}

void	sort_big(t_stack *a, t_stack *b)
{
	push(a, b, "pb");
	push(a, b, "pb");
	sort_a(a, b);
	// sort_three(a);
	// empty_b(a, b);
	// while (ft_is_sort(a->stack, a->size) == FALSE)
	// 	reverse_rotate(a, "rra");
}

int	sort_a(t_stack *a, t_stack *b)
{
	int	*costs;

	while (a->size > 3)
	{
		costs = get_costs(a, b);
		if (!costs)
			return (0);
		a->pos = get_first_min(costs, a->size);
		b->pos = get_pos_b(b, a->stack[a->pos]);
		a->move = cost_move_top(a, a->pos);
		b->move = cost_move_top(b, b->pos);
		move_pos_top(a, b);
		push(a, b, "pb");
		free(costs);
	}
	return (1);
}

void	empty_b(t_stack *a, t_stack *b)
{
	while (b->size != 0)
	{
		a->max = get_max(a->stack, a->size);
		a->min = get_min(a->stack, a->size);
		if (b->stack[0] < a->min || b->stack[0] > a->max)
		{
			a->pos = get_value_pos(a, a->min);
			a->move = cost_move_top(a, a->pos);
			while (a->move != 0)
				move_top_one(a, 'a');
			push(b, a, "pa");
		}
		else if (a->stack[0] - 1 == b->stack[0])
			push(b, a, "pa");
		else
		{
			a->pos = get_target_pos_a(a, b->stack[0]);
			a->move = cost_move_top(a, a->pos);
			while (a->move != 0)
				move_top_one(a, 'a');
			push(b, a, "pa");
		}
	}
}
