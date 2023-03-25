/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:43:14 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/25 01:32:04 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int get_target_pos_b(t_stack *b, int nb_a);

int	get_pos_b(t_stack *b, int nb_a)
{
	b->min = get_min(b->stack, b->size);
	b->max = get_max(b->stack, b->size);
	if (nb_a > b->max || nb_a < b->min)
		return (get_value_pos(b, b->max));
	else
		return (get_target_pos_b(b, nb_a));
	return (0);
}

int get_target_pos_b(t_stack *b, int nb_a)
{
	int	target;

	target = nb_a;
	while (target != b->min)
	{
		target--;
		if (get_value_pos(b, target) != -1)
			return (get_value_pos(b, target));
	}
	return (0);
}

int get_target_pos_a(t_stack *a, int nb_b)
{
	int target;

	target = nb_b;
	while (target != a->max)
	{
		target++;
		if (get_value_pos(a, target) != -1)
			return (get_value_pos(a, target));
	}
	return (0);
}

int	get_value_pos(t_stack *stack, int value)
{
	int i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
