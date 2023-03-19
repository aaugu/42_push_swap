/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:17:55 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/19 19:02:21 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	game_solve(t_stack *a, t_stack *b, int med)
{
	if (a->size >= 2 && a->size <= 3)
		sort_small_a(a);
	else
		solve(a, b, med);
}

void	get_min_max(int *list, int size, int *min, int *max)
{
	int	i;

	*min = list[0];
	*max = list[0];
	i = 1;
	while (i < size)
	{
		if (list[i] < *min)
			*min = list[i];
		if (list[i] > *max)
			*max = list[i];
		i++;
	}
}

void	solve(t_stack *a, t_stack *b, int med)
{
	sort_a(a, b, med);
	while (b->size != 0)
	{
		push(b, a, "pa");
		if (a->stack[0] > a->stack[1])
			rotate(a, "ra");
	}
}

void	sort_a(t_stack *a, t_stack *b, int med)
{
	int	min;
	int	max;

	(void) med;
	get_min_max(a->stack, a->size, &min, &max);
	while (!ft_is_sort(a->stack, a->size))
	{
		if (a->size >= 2 && a->size <= 3)
			sort_small_a(a);
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

void	sort_small_a(t_stack *a)
{
	while (!ft_is_sort(a->stack, a->size))
	{
		if (a->stack[0] > a->stack[1])
			swap(a->stack, "sa");
		else
			reverse_rotate(a, "rra");
	}
}
