/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:17:04 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/14 10:02:51 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(int **list, int size, t_game *game)
{
	int	*new_list;
	int	i;

	if (size >= 2)
	{
		new_list = (int *)malloc(sizeof(int) * size);
		if (!new_list)
			return ;
		new_list[0] = list[0][1];
		new_list[1] = list[0][0];
		i = 2;
		while (i < size)
		{
			new_list[i] = list[0][i];
			i++;
		}
		free(*list);
		*list = new_list;
		if (list == &game.stack_a)
			ft_printf("sa\n");
		if (list == &game.stack_b)
			ft_printf("sb\n");
	}
}
