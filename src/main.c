/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:08:55 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/10 14:06:23 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (0);
	game->list = get_args(argv, argc);
	if (!game->list)
	{
		clear_game(game);
		return (0);
	}
	if (!is_list_valid(game))
	{
		clear_game(game);
		return (0);
	}
	game_init(game);
	sort_list(game);
	clear_game(game);
	return (0);
}

void	clear_game(t_game *game)
{
	void	(*del)(void *);

	del = &delete_content;
	if (game->list)
		ft_strs_free(game->list, game->l_size);
	if (game->stack_a)
		ft_lstclear(&(game->stack_a), del);
	if (game->stack_b)
		ft_lstclear(&(game->stack_a), del);
	free(game);
}

void	delete_content(void *content)
{
	content = NULL;
}
