/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:59:28 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/29 14:22:48 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		sort_b_in_a(t_stack *a, t_stack *b);
void	fill_b_to_median(t_stack *a, t_stack *b, int median);
void	final_sort(t_stack *a);
t_bool	has_values_under_med(t_stack *a, int median);

void	sort_big(t_stack *a, t_stack *b, int median)
{
	fill_b_to_median(a, b, median);
	while (a->size > 3)
	{
		push(a, b, "pb");
	}
	sort_three(a);
	sort_b_in_a(a, b);
	final_sort(a);
}

void	fill_b_to_median(t_stack *a, t_stack *b, int median)
{
	while (has_values_under_med(a, median) == TRUE)
	{
		if (a->stack[0] <= median)
			push(a, b, "pb");
		else
			rotate(a, "ra");
	}
}

int	sort_b_in_a(t_stack *a, t_stack *b)
{
	int	*costs;

	while (b->size != 0)
	{
		a->min = get_min(a->stack, a->size);
		a->max = get_max(a->stack, a->size);
		b->max = get_max(b->stack, b->size);
		costs = get_costs(a, b);
		if (!costs)
			return (0);
		b->pos = get_first_min(costs, b->size);
		a->pos = get_pos_a(a, b, b->pos);
		a->move = cost_move_top(a, a->pos);
		b->move = cost_move_top(b, b->pos);
		move_pos_top(a, b);
		push(b, a, "pa");
		free(costs);
	}
	return (1);
}

void	final_sort(t_stack *a)
{
	a->min = get_min(a->stack, a->size);
	if (is_at_begin(get_value_pos(a, a->min), a->size))
	{
		while (ft_is_sort(a->stack, a->size) == FALSE)
			rotate(a, "ra");
	}
	else
	{
		while (ft_is_sort(a->stack, a->size) == FALSE)
			reverse_rotate(a, "rra");
	}
}

t_bool	has_values_under_med(t_stack *a, int median)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->stack[i++] <= median)
			return (1);
	}
	return (0);
}
