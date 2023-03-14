/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:17:11 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/14 10:02:43 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(int **list, int size, t_game *game)
{
	int	*new_list;
	int	i;
	int	j;

	new_list = (int *)malloc(sizeof(int) * size);
	if (!new_list)
		return ;
	new_list[size - 1] = list[0][0];
	i = 0;
	j = 1;
	while (i < size - 1)
	{
		new_list[i] = list[0][j];
		i++;
		j++;
	}
	free(*list);
	*list = new_list;
	if (list == &game.stack_a)
		ft_printf("ra\n");
	if (list == &game.stack_b)
		ft_printf("rb\n");
}
