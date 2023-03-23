/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:17:55 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/23 10:26:32 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	solve(t_stack *a, t_stack *b)
{
	if (a->size >= 2 && a->size <= 3)
		sort_three(a);
	else if (a->size > 3 && a->size <= 5)
		sort_small(a, b);
	else
		sort_big(a, b);
}

int	get_min(int *list, int size)
{
	int	min;
	int	i;

	min = list[0];
	i = 1;
	while (i < size)
	{
		if (list[i] < min)
			min = list[i];
		i++;
	}
	return (min);
}

int	get_max(int *list, int size)
{
	int	max;
	int	i;

	max = list[0];
	i = 1;
	while (i < size)
	{
		if (list[i] > max)
			max = list[i];
		i++;
	}
	return (max);
}


int	get_first_min(int *list, int size)
{
	int	min;
	int	i;

	min = get_min(list, size);
	i = 0;
	while (list[i] != min)
		i++;
	return (i);
}
