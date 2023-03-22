/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:08:55 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/22 19:00:25 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 1)
		return (0);
	game.list = get_input(argv, argc);
	if (!game.list)
		error("Error\n");
	game.size = ft_strs_len(game.list);
	if (is_list_valid(game.list, game.size) == FALSE)
	{
		ft_strs_free(game.list, game.size);
		error("Error\n");
	}
	if (!init_stacks(game.list, game.size, &game.a, &game.b))
	{
		ft_strs_free(game.list, game.size);
		error("Error\n");
	}
	ft_strs_free(game.list, game.size);
	if (ft_is_sort(game.a.stack, game.a.size) == FALSE)
		solve(&game.a, &game.b);
	free(game.a.stack);
	free(game.b.stack);
	return (0);
}

void	error(char *error)
{
	ft_printf(error);
	exit(0);
}
