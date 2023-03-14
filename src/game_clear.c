/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:17:00 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/14 18:10:52 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	game_clear(t_game game)
{
	if (game.list)
	{
		ft_printf("ici 1 \n");
		ft_strs_free(game.list, game.size);
	}
	ft_printf("ptr : %p\n", game.a.content);
	if (game.a.content[0])
	{
		free(game.a.content);
		ft_printf("ici 2 \n");
	}
	if (game.b.content)
	{
		ft_printf("ici 3 \n");
		free(game.b.content);
	}
	ft_printf("Thanks for trying push_swap");
	exit(0);
}
