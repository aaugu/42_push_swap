/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:58:23 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/30 11:20:45 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		*create_stack(char **list, int size);
int		get_median(t_game *game);

int	init_stacks(t_game *game)
{
	game->a.size = game->size;
	game->a.stack = create_stack(game->list, game->size);
	if (!game->a.stack)
		return (0);
	game->b.size = 0;
	game->b.stack = (int *)ft_calloc(sizeof(int), game->size);
	if (!game->b.stack)
	{
		free(game->a.stack);
		return (0);
	}
	game->median = get_median(game);
	return (1);
}

int	*create_stack(char **list, int size)
{
	int	i;
	int	*stack;

	stack = (int *)ft_calloc(sizeof(int), size);
	if (!stack)
		return (0);
	i = 0;
	while (i < size)
	{
		stack[i] = ft_atoi(list[i]);
		i++;
	}
	return (stack);
}

int	get_median(t_game *game)
{
	int	*copy;
	int	median;

	copy = create_stack(game->list, game->a.size);
	if (!copy)
		clear_error_exit(game, "Error\nSomething went wrong.");
	median = ft_median(copy, game->a.size);
	free(copy);
	return (median);
}
