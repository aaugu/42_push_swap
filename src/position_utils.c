/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:43:14 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/27 14:42:49 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_target_pos_a(t_stack *a, int nb_b);
int	get_value_pos(t_stack *stack, int value);

int	get_pos_a(t_stack *a, int nb_b, int b_max)
{
	a->min = get_min(a->stack, a->size);
	if (nb_b > b_max)
		return (get_value_pos(a, a->min));
	else
		return (get_target_pos_a(a, nb_b));
	return (0);
}

int	get_target_pos_a(t_stack *a, int nb_b)
{
	while (nb_b != a->max)
	{
		nb_b++;
		if (get_value_pos(a, nb_b) != -1)
			return (get_value_pos(a, nb_b));
	}
	return (0);
}

int	get_value_pos(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
