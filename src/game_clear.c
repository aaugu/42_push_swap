/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:17:00 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/13 11:17:18 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	game_clear(t_game *game)
{
	if (game->list)
		ft_strs_free(game->list, game->size);
	if (game->stack_a)
		free(game->stack_a);
	if (game->stack_b)
		free(game->stack_b);
	free(game);
	ft_printf("Thanks for trying push_swap");
	exit(0);
}
