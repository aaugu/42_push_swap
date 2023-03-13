/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:17:16 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/13 11:08:13 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate(int **list, int size, t_game *game)
{
	int	*new_list;
	int	i;
	int	j;

	new_list = (int *)malloc(sizeof(int) * size);
	if (!new_list)
		return ;
	new_list[0] = list[0][size - 1];
	i = 1;
	j = 0;
	while (i < size)
	{
		new_list[i] = list[0][j];
		i++;
		j++;
	}
	free(*list);
	*list = new_list;
	if (list == &game->stack_a)
		ft_printf("rra\n");
	if (list == &game->stack_b)
		ft_printf("rrb\n");
}
