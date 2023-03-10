/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:00:06 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/10 15:15:14 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	game_init(t_game *game)
{
	// get_min(game);
	// get_max(game);
	create_stack_a(game);
	if (!*(game->stack_a))
		return ;
}

void	create_stack_a(t_game *game)
{
	t_lstnb	*temp;
	t_lstnb	*prev;
	int		i;

	i = 1;
	*(game->stack_a) = lstnew(ft_atoi(game->list[0]));
	if (!*(game->stack_a))
		return ;
	prev = *(game->stack_a);
	while (i < game->l_size)
	{
		temp = lstnew(ft_atoi(game->list[i]));
		if (!temp)
			return ;
		prev->next = temp;
		prev = temp;
		i++;
	}
}
