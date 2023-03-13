/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:17:55 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/13 14:35:55 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	game_solve(int **stack_a, int **stack_b, t_game *game)
{
	int	*a;
	int	*b;

	a = *stack_a;
	b = *stack_b;
	while (!is_stack_ordered(a, game->size_a) && game->size_b == 0)
	{
		if (a[0] == game->min)
		{
			push_b(&a, &b, game);
			game->min = get_min(a, game->size_a);
		}
		if (a[0] == game->max)
		{
			push_b(&a, &b, game);
			game->max = get_max(a, game->size_a);
		}
		else if (a[0] > a[1])
			swap(&a, game->size_a, game);
		else if (a[0] < a[1])
			reverse_rotate(&a, game->size_a, game);
		else if (is_stack_ordered(a, game->size_a) && game->size_b != 0)
			push_a(&a, &b, game);
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
