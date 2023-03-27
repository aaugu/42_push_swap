/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:59:25 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/27 15:18:18 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_small_a(t_stack *a, t_stack *b);

void	sort_small(t_stack *a, t_stack *b)
{
	sort_small_a(a, b);
	while (b->size != 0)
	{
		push(b, a, "pa");
		if (a->stack[0] > a->stack[1])
			rotate(a, "ra");
	}
}

void	sort_small_a(t_stack *a, t_stack *b)
{
	a->min = get_min(a->stack, a->size);
	a->max = get_max(a->stack, a->size);
	while (ft_is_sort(a->stack, a->size) == FALSE)
	{
		if (a->size >= 2 && a->size <= 3)
			sort_three(a);
		else if (a->stack[0] == a->min || a->stack[0] == a->max)
		{
			push(a, b, "pb");
			a->min = get_min(a->stack, a->size);
			a->max = get_max(a->stack, a->size);
		}
		else if (a->stack[0] > a->stack[1])
			swap(a->stack, "sa");
		else
			reverse_rotate(a, "rra");
	}
}
