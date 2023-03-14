/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:00:06 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/14 10:03:11 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	game_init(t_game *game)  // this should return int
{
	create_stack_a(game);
	if (!(game.stack_a)
		return ;
	game.stack_b = (int *)malloc(sizeof(int));
	if (!game.stack_b)
		return ;
	game.stack_b[0] = 0;
	game.size_a = game.size;
	game.size_b = 0;
	game.min = get_min(game.stack_a, game.size);
	game.max = get_max(game.stack_a, game.size);
}

void create_stack_a(t_game *game) // this should return int
{
	int	i;

	game.stack_a = (int *)malloc(sizeof(int) * (game.size));
	if (!game.stack_a)
		return ;
	i = 0;
	while (i < (game.size))
	{
		game.stack_a[i] = ft_atoi(game.list[i]);
		i++;
	}
}

void	get_min_max(int	*list, int size, int* min, int* max)  // do min and max in the same loop. Return min and max as pointer
{
	int	i;
	int	min;
	int max....

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

int	get_max(int	*list, int size)
{
	int	i;
	int	max;

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
