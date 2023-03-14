/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:00:06 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/14 18:02:28 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	game_init(t_game game)
{

	game.a.size = game.size;
	game.a.content = create_stack(game.list, game.size, game.a.size);
	if (!game.a.content)
		return (0);
	game.b.size = 0;
	game.b.content = create_stack(game.list, game.size, game.b.size);
	if (!game.b.content)
		return (0);
	get_min_max(game.a.content, game.size, &game.min, &game.max);
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

void	get_min_max(int	*list, int size, int *min, int *max)
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
