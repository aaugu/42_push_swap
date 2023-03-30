/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:08:55 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/30 11:16:00 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
