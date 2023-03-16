/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:08:55 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/14 23:15:08 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game.list = NULL;
	game.a.content = NULL;
	game.b.content = NULL;
	game.list = get_args(argv, argc);
	if (!game.list)
		game_clear(&game);
	game.size = ft_strs_len(game.list);
	if (!is_list_valid(game.list, game.size))
		game_clear(&game);
	if (!game_init(&game))
	{
		ft_printf("Error\nSomething went wrong while creating stacks.");
		game_clear(&game);
	}
	game_solve(&game.a, &game.b);
	game_clear(&game);
	return (0);
}
