/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:00:06 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/14 11:13:50 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	game_init(t_game game)
{
	if (!create_stack(game.a, game.list, game.size, game.size))
		return (-1);
	if (!create_stack(game.b, game.list, game.size, 0))
		return (-1);
	get_min(game.a.content, game.size, &game.min, &game.max);
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
	int	min_v;
	int	max_v;

	min_v = list[0];
	max_v = list[0];
	i = 1;
	while (i < size)
	{
		if (list[i] < min_v)
			min_v = list[i];
		if (list[i] < max_v)
			max_v = list[i];
		i++;
	}
	min = min_v;
	max = max_v;
}
