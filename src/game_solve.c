/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:17:55 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/15 00:09:32 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	game_solve(t_stack *a, t_stack *b)
{
	int	min;
	int	max;

	get_min_max(a->content, a->size, &min, &max);
	while (!is_stack_ordered(a->content, a->size))
	{
		if (a->content[0] == min || a->content[0] == max)
		{
			push(a, b, "pb");
			get_min_max(a->content, a->size, &min, &max);
		}
		else if (a->content[0] > a->content[1])
			swap(a->content, "sa");
		else
			reverse_rotate(a, "rra");
	}
	while (b->size != 0)
	{
		push(b, a, "pa");
		if (a->content[0] > a->content[1])
			rotate(a, "ra");
	}
}

t_bool	is_stack_ordered(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
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
