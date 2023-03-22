/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:58:23 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/22 12:07:09 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	init_stacks(t_game *game)
{
	game->a.size = game->size;
	game->a.stack = create_stack(game->list, game->size, game->a.size);
	if (!game->a.stack)
		return (0);
	game->b.size = 0;
	game->b.stack = (int *)ft_calloc(sizeof(int), game->size);
	if (!game->b.stack)
	{
		free(game->a.stack);
		return (0);
	}
	convert_int(game->list, &game->a);
	return (1);
}

int	*create_stack(char **list, int l_size, int s_size)
{
	int	i;
	int	*stack;

	stack = (int *)ft_calloc(sizeof(int), l_size);
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

void	convert_int(char **list, t_stack *a)
{
	int	*copy;
	int	i;
	int	j;

	copy = create_stack(list, a->size, a->size);
	ft_sort(copy, a->size);
	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (a->stack[i] == copy[j])
			{
				a->stack[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(copy);
}
