/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 23:18:19 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/10 23:40:34 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_bool	is_list_valid(t_game *game)
{
	game->size = ft_strs_len(game->list);
	if (!game->size)
	{
		ft_printf("Error\nList empty.\n");
		return (0);
	}
	if (!only_num(game->list, game->size))
	{
		ft_printf("Error\nNon numeric parameter in the list.\n");
		return (0);
	}
	if (!no_duplicate_num(game->list, game->size))
	{
		ft_printf("Error\nList has duplicates.\n");
		return (0);
	}
	return (1);
}

t_bool	only_num(char **list, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!is_num(list[i]))
			return (0);
		i++;
	}
	return (1);
}

t_bool	is_num(char *str)
{
	char	*str_n;

	str_n = ft_itoa(ft_atoi(str));
	if (!str_n)
		return (0);
	if (!ft_strcmp(str, str_n))
	{
		free(str_n);
		return (1);
	}
	free(str_n);
	return (0);
}

t_bool	no_duplicate_num(char **list, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (!ft_strcmp(list[i], list[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
