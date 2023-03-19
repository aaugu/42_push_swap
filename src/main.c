/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:08:55 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/19 19:10:48 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game.list = get_args(argv, argc);
	if (!game.list)
	{
		ft_printf("Error\n");
		return (0);
	}
	game.size = ft_strs_len(game.list);
	if (game.size == 1)
		return (0);
	if (!is_list_valid(game.list, game.size))
	{
		ft_strs_free(game.list, game.size);
		ft_printf("Error\n");
		return (0);
	}
	game.copy = create_stack(game.list, game.size, game.size);
	if (!game.copy)
	{
		ft_strs_free(game.list, game.size);
		ft_printf("Error\n");
		return (0);
	}
	if (ft_is_sort(game.copy, game.size))
		return (0);
	ft_sort(game.copy, game.size);
	game.med = ft_median(game.copy, game.size);
	free(game.copy);
	if (!game_init(&game))
	{
		ft_printf("Error\n");
		return (0);
	}
	ft_strs_free(game.list, game.size);
	game_solve(&game.a, &game.b, game.med);
	free(game.a.stack);
	free(game.b.stack);
	return (0);
}
