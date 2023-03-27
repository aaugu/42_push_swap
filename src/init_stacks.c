/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:58:23 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/27 15:42:05 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		*create_stack(char **list, int size);
void	convert_int_and_get_med(char **list, t_stack *a);
int		get_median(char **list, t_stack a);

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
	game->median = get_median(game->list, game->a);
	if (game->median == ERROR)
		return (0);
	convert_int_and_get_med(game->list, &game->a);
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

void	convert_int_and_get_med(char **list, t_stack *a)
{
	int	*copy;
	int	i;
	int	j;

	copy = create_stack(list, a->size);
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

int	get_median(char **list, t_stack a)
{
	int	*copy;
	int	median;
	int	i;

	copy = create_stack(list, a.size);
	if (!copy)
		return (-1);
	ft_sort(copy, a.size);
	median = ft_median(copy, a.size);
	i = 0;
	while (i < a.size)
	{
		if (copy[i] == median)
		{
			return (i);
			free(copy);
		}
		i++;
	}
	free(copy);
	return (-1);
}
