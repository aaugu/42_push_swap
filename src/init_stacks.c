/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:58:23 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/22 18:59:11 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		*create_stack(char **list, int l_size, int s_size);
void	convert_int(char **list, t_stack *a);

int	init_stacks(char **list, int size, t_stack *a, t_stack *b)
{
	a->size = size;
	a->stack = create_stack(list, size, a->size);
	if (!a->stack)
		return (0);
	b->size = 0;
	b->stack = (int *)ft_calloc(sizeof(int), size);
	if (!b->stack)
	{
		free(a->stack);
		return (0);
	}
	convert_int(list, a);
	return (1);
}

int	*create_stack(char **list, int l_size, int s_size)
{
	int	i;
	int	*stack;

	stack = (int *)ft_calloc(sizeof(int), l_size);
	if (!stack)
		return (0);
	i = 0;
	while (i < s_size)
	{
		stack[i] = ft_atoi(list[i]);
		i++;
	}
	return (stack);
}

void	convert_int(char **list, t_stack *a)
{
	int	*copy;
	int	i;
	int	j;

	copy = create_stack(list, a->size, a->size);
	ft_sort(copy, a->size);
	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (a->stack[i] == copy[j])
			{
				a->stack[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(copy);
}
