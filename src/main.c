/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:08:55 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/13 11:09:12 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	int	i;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (0);
	game->stack_a = NULL;
	game->stack_b = NULL;
	game->list = get_args(argv, argc);
	if (!game->list)
		clear_game(game);
	if (!is_list_valid(game))
		clear_game(game);
	game_init(game);
	push_b(&game->stack_a, &game->stack_b, game);
	reverse_rotate(&game->stack_a, game->size_a, game);
	reverse_rotate(&game->stack_a, game->size_a, game);
	reverse_rotate(&game->stack_a, game->size_a, game);
	push_a(&game->stack_a, &game->stack_b, game);
	rotate(&game->stack_a, game->size_a, game);
	clear_game(game);
	return (0);
}

void	clear_game(t_game *game)
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
