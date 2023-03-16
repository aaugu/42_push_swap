/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:00:06 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/16 16:03:30 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	game_init(t_game *game)
{
	game->a.size = game->size;
	game->copy = create_stack(game->list, game->size, game->a.size);
	if (!game->a.stack)
		return (0);
	game->a.stack = create_stack(game->list, game->size, game->a.size);
	if (!game->a.stack)
		return (0);
	game->b.size = 0;
	game->b.stack = create_stack(game->list, game->size, game->b.size);
	if (!game->b.stack)
		return (0);
	return (1);
}

int	*create_stack(char **list, int l_size, int s_size)
{
	int	i;
	int	*stack;

	stack = (int *)malloc(sizeof(int) * (l_size));
	if (!stack)
		return (0);
	i = 0;
	while (i < s_size)
	{
		stack[i] = ft_atoi(list[i]);
		i++;
	}
	return (stack);
}
