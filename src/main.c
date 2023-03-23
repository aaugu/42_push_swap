/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:08:55 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/23 15:27:54 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	error_exit(char *error);
void	clear_error_exit(t_game *game, char *error);

int	main(int argc, char **argv)
{
	t_game	game;

	game.a.stack = NULL;
	game.b.stack = NULL;
	game.list = get_input(argv, argc);
	if (!game.list)
		error_exit("Error\n");
	game.size = ft_strs_len(game.list);
	if (is_list_valid(game.list, game.size) == FALSE)
		clear_error_exit(&game, "Error\n");
	if (!init_stacks(game.list, game.size, &game.a, &game.b))
		clear_error_exit(&game, "Error\n");
	ft_strs_free(game.list, game.size);
	if (ft_is_sort(game.a.stack, game.a.size) == FALSE)
		solve(&game.a, &game.b);
	free(game.a.stack);
	free(game.b.stack);
	return (0);
}

void	error_exit(char *error)
{
	ft_printf(error);
	exit(0);
}

void	clear_error_exit(t_game *game, char *error)
{
	ft_strs_free(game->list, game->size);
	if (!game->a.stack)
		free(game->a.stack);
	if (!game->b.stack)
		free(game->b.stack);
	error_exit(error);
}

// -39 -11 32 45 38 10 -15 -27 -13 0 30 18 -14 -16 41 28 -19 26 -20 -32 -45 8 24 -42 3 -31 13 29 40 6 11 -17 -2 1 19 -12 33 43 -36 -24 12 -28 -1 -9 -38 42 -47 27 15 14 -3 2 25 -10 21 -40 -41 -29 -35 -18 -30 -50 22 -6 -4 -23 -48 44 -37 47 49 34 35 31 4 9 -8 46 -22 -46 -21 -34 5 -44 -49 7 48 20 39 -33 -25 16 -26 36 37 -5 -43 23 17 -7