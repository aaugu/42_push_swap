/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:17:00 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/16 16:03:22 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	game_clear(t_game *game)
{
	if (game->list)
		ft_strs_free(game->list, game->size);
	if (game->copy)
		free(game->copy);
	if (game->a.stack)
		free(game->a.stack);
	if (game->b.stack)
		free(game->b.stack);
	exit(0);
}
