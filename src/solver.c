/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:17:55 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/27 15:18:23 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	solve(t_game *game)
{
	if (game->a.size >= 2 && game->a.size <= 3)
		sort_three(&game->a);
	else
		sort_big(&game->a, &game->b, game->median);
}

void	sort_three(t_stack *a)
{
	while (ft_is_sort(a->stack, a->size) == FALSE)
	{
		if (a->stack[0] > a->stack[1])
			swap(a->stack, "sa");
		else
			reverse_rotate(a, "rra");
	}
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
