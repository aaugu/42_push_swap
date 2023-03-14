/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:17:55 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/14 11:40:21 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	game_solve(t_stack a, t_stack b, int *min, int *max)
{
	while (!is_stack_ordered(a.content, a.size))  // this should be a ||
	{
		if (a.content[0] == min || a.content[0] == max)
		{
			push(a, b, "");
			get_min_max(a.content, a.size, min, max);
		}
		else if (a[0] > a[1])
			swap(a.content, "sa");
		else
			reverse_rotate(a, "rra");
	}
	while (b.size != 0)
	{
		push(b, a, "pb");
		if (a[0] > a[1])
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
