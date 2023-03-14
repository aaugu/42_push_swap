/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:08:55 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/14 18:02:21 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_game	game;
	// int	i;

	game.list = get_args(argv, argc);
	if (!game.list)
		game_clear(game);
	game.size = ft_strs_len(game.list);
	if (!is_list_valid(game.list, game.size))
		game_clear(game);
	// i = 0;
	// while (i < game.size)
	// {
	// 	ft_printf("%s\n", game.list[i]);
	// 	i++;
	// }
	if (!game_init(game))
	{
		ft_printf("Error\nSomething went wrong while creating stacks.");
		game_clear(game);
	}
	// ft_printf("Min : %d\n", game.min);
	// ft_printf("Max : %d\n", game.max);
	// game_solve(game.a, game.b, &game.min, &game.max);
	game_clear(game);
	return (0);
}
