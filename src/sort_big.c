/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:59:28 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/22 18:28:32 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		sort_a(t_stack *a, t_stack *b);
void	empty_b(t_stack *a, t_stack *b);

void	sort_big(t_stack *a, t_stack *b)
{
	push(a, b, "pb");
	push(a, b, "pb");
	if (!sort_a(a, b))
		error("Error\n");
	if (a->stack[1] == b->stack[0] + 1 && a->stack[0] < a->stack[2])
		swap(a, "sa");
	else if (!(a->stack[0] == b->stack[0] + 1 && a->stack[1] < a->stack[2]))
		sort_three(a);
	empty_b(a, b);
	while (ft_is_sort(a->stack, a->size) == FALSE)
	{
		reverse_rotate(a, "rra");
	}
}

int	sort_a(t_stack *a, t_stack *b)
{
	int	*costs;
	int	to_move;

	while (a->size > 3)
	{
		costs = get_costs(a, b);
		if (!costs)
			return (0);
		to_move = get_first_min(costs, (a->size + b->size));
		do_moves(a, b, to_move, get_pos_b(b, a->stack[to_move]));
		free(costs);
	}
}

int get_first_min(int *list, int size)
{
	int min;
	int i;

	min = get_min(list, size);
	i = 0;
	while (list[i] != min)
		i++;
	return (i);
}

void	empty_b(t_stack *a, t_stack *b)
{
	while (b->size != 0)
	{
		if (b->stack[0] > a->stack[0])
			push(b, a, "pb");
		else
			reverse_rotate(a, "rra");
	}
}
