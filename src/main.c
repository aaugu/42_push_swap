/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:08:55 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/14 10:17:39 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game.list = get_args(argv, argc);
	if (!game.list)
		game_clear(&game);
	game.size = ft_strs_len(game.list);
	if (!is_list_valid(game.list, game.size))
		game_clear(&game);
	game_init(game);  // react on return
	game_solve(&game.stack_a, &game.stack_b, game);
	game_clear(game);
	return (0);
}
