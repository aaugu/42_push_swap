/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:08:55 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/16 16:47:25 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_game	game;
	// int		i;

	game.list = get_args(argv, argc);
	if (!game.list)
		game_clear(&game);
	game.size = ft_strs_len(game.list);
	if (!is_list_valid(game.list, game.size))
	{
		ft_printf("Error\n");
		game_clear(&game);
	}
	if (!game_init(&game))
	{
		ft_printf("Error\n");
		game_clear(&game);
	}
	ft_sort(game.copy, game.size);
	game.med = ft_median(game.copy, game.size);
	game_solve(&game.a, &game.b, game.med);
	game_clear(&game);
	return (0);
}
