/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:59:25 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/22 12:01:39 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void sort_small(t_stack *a, t_stack *b)
{
	sort_small_a(a, b);
	while (b->size != 0)
	{
		push(b, a, "pa");
		if (a->stack[0] > a->stack[1])
			rotate(a, "ra");
	}
}

void sort_small_a(t_stack *a, t_stack *b)
{
	int min;
	int max;

	get_min_max(a->stack, a->size, &min, &max);
	while (!ft_is_sort(a->stack, a->size))
	{
		if (a->size >= 2 && a->size <= 3)
			sort_three(a);
		else if (a->stack[0] == min || a->stack[0] == max)
		{
			push(a, b, "pb");
			get_min_max(a->stack, a->size, &min, &max);
		}
		else if (a->stack[0] > a->stack[1])
			swap(a->stack, "sa");
		else
			reverse_rotate(a, "rra");
	}
}

void sort_three(t_stack *a)
{
	while (!ft_is_sort(a->stack, a->size))
	{
		if (a->stack[0] > a->stack[1])
			swap(a->stack, "sa");
		else
			reverse_rotate(a, "rra");
	}
}
