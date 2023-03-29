/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_position_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:43:14 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/29 20:32:07 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_target_pos_a(t_stack *a, int nb_b);
int	get_value_pos(t_stack *stack, int value);

int	get_pos_a(t_stack *a, t_stack *b, int i)
{
	int	pos_a;

	if (b->stack[i] > a->max)
	{
		pos_a = get_value_pos(a, a->min);
		return (pos_a);
	}
	else
	{
		pos_a = get_target_pos_a(a, b->stack[i]);
		return (pos_a);
	}
	return (0);
}

int	get_target_pos_a(t_stack *a, int nb_b)
{
	int	nb_a;

	while (nb_b != a->max)
	{
		nb_b++;
		nb_a = get_value_pos(a, nb_b);
		if (nb_a != -1)
			return (nb_a);
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
