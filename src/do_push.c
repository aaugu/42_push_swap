/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:16:46 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/13 21:33:58 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_a(int **src, int **dest, t_game *game)
// void push_a(t_tower* a, t_tower* b)
{
	int	*new_a;
	int	*new_b;

	if (game->size_b > 0)
	{
		game->size_a++;
		game->size_b--;
		new_a = add_up(*a, (*b)[0], game->size_a);
		if (!new_a)
			return ;
		new_b = remove_up(*b, game->size_b);
		if (!new_b)
			return ;
		free(*a);
		*a = new_a;
		free(*b);
		*b = new_b;
		ft_printf("pa\n");
	}
}

void	push_b(int **a, int **b, t_game *game)
{
	int	*new_a;
	int	*new_b;

	if (game->size_a > 0)
	{
		game->size_a--;
		game->size_b++;
		new_a = remove_up(*a, game->size_a);
		if (!new_a)
			return ;
		new_b = add_up(*b, (*a)[0], game->size_b);
		if (!new_b)
			return ;
		free(*a);
		*a = new_a;
		free(*b);
		*b = new_b;
		ft_printf("pb\n");
	}
}

int	*add_up(int *src, int to_add, int size)
{
	int	*new;
	int	i;
	int	j;

	new = (int *)malloc(sizeof(int) * size);
	if (!new)
		return (0);
	new[0] = to_add;
	i = 1;
	j = 0;
	while (i < size)
	{
		new[i] = src[j];
		i++;
		j++;
	}
	return (new);
}

int	*remove_up(int *list, int size)
{
	int	*new;
	int	i;
	int	j;

	new = (int *)malloc(sizeof(int) * size);
	if (!new)
		return (0);
	i = 0;
	j = 1;
	while (i < size)
	{
		new[i++] = list[j++];
	}
	return (new);
}
