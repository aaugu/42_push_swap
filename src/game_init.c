/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:00:06 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/14 14:07:44 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	game_init(t_game game)
{
	game.a.content = NULL;
	game.b.content = NULL;
	if (!create_stack(game.a, game.list, game.size, game.size))
		return (0);
	if (!create_stack(game.b, game.list, game.size, 0))
		return (0);
	get_min_max(game.a.content, game.size, &game.min, &game.max);
	return (1);
}

int	create_stack(t_stack stack, char **list, int l_size, int s_size)
{
	int	i;

	stack.content = (int *)malloc(sizeof(int) * (l_size));
	if (!stack.content)
		return (0);
	i = 0;
	while (i < l_size)
	{
		stack.content[i] = ft_atoi(list[i]);
		i++;
	}
	stack.size = s_size;
	return (1);
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
