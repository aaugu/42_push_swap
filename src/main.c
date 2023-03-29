/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:08:55 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/29 14:25:32 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	clear_error_exit(t_game *game, char *error);

int	main(int argc, char **argv)
{
	t_game	game;

	game.a.stack = NULL;
	game.b.stack = NULL;
	if (argc == 1)
		return (0);
	game.list = get_input(argv, argc);
	if (!game.list)
		clear_error_exit(&game, "Error\n");
	game.size = ft_strs_len(game.list);
	if (is_list_valid(game.list, game.size) == FALSE)
		clear_error_exit(&game, "Error\n");
	if (!init_stacks(&game))
		clear_error_exit(&game, "Error\n");
	ft_strs_free(game.list, game.size);
	if (ft_is_sort(game.a.stack, game.a.size) == FALSE)
		solve(&game);
	free(game.a.stack);
	free(game.b.stack);
	return (0);
}

void	clear_error_exit(t_game *game, char *error)
{
	if (!game->list)
		ft_strs_free(game->list, game->size);
	if (!game->a.stack)
		free(game->a.stack);
	if (!game->b.stack)
		free(game->b.stack);
	ft_printf(error);
	exit(0);
}

void	print_stack(t_stack *stack, char *suffix)
{
	int	i;

	i = 0;
	while (i < stack->size)
		ft_printf("%d ", stack->stack[i++]);
	if (suffix)
		ft_printf("%s", suffix);
	else
		ft_printf("\n");
}

// -39 -11 32 45 38 10 -15 -27 -13 0 30 18 -14 -16 41 28 -19 26 -20 -32 -45 8 24 -42 3 -31 13 29 40 6 11 -17 -2 1 19 -12 33 43 -36 -24 12 -28 -1 -9 -38 42 -47 27 15 14 -3 2 25 -10 21 -40 -41 -29 -35 -18 -30 -50 22 -6 -4 -23 -48 44 -37 47 49 34 35 31 4 9 -8 46 -22 -46 -21 -34 5 -44 -49 7 48 20 39 -33 -25 16 -26 36 37 -5 -43 23 17 -7
