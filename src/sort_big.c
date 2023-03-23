/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:59:28 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/23 15:50:29 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		sort_a(t_stack *a, t_stack *b);
void	empty_b(t_stack *a, t_stack *b);

void	sort_big(t_stack *a, t_stack *b)
{
	push(a, b, "pb");
	push(a, b, "pb");
	if (!sort_a(a, b))
		error_exit("Error\n");
	sort_three(a);
	empty_b(a, b);
	while (ft_is_sort(a->stack, a->size) == FALSE)
		reverse_rotate(a, "rra");
}

int	sort_a(t_stack *a, t_stack *b)
{
	int	*costs;

	while (a->size > 3)
	{
		b->min = get_min(b->stack, b->size);
		b->max = get_max(b->stack, b->size);
		costs = get_costs(a, b);
		if (!costs)
			return (0);
		a->pos = get_first_min(costs, a->size);
		b->pos = get_pos_b(b, a->stack[a->pos]);
		moves_top(a, b);
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
		if (a->stack[0] == b->stack[0] + 1)
			push(b, a, "pa");
		else if (b->stack[0] > a->max)
		{
			a->pos = get_min(a->stack, a->size);
			while (a->stack[0] != a->min)
				move_top_one(a, 'a');
			push(b, a, "pa");
		}
		else
			reverse_rotate(a, "rra");
	}
}
