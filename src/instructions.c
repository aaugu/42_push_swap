/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:49:38 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/19 12:34:16 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack *src, t_stack *dest, char *instruction)
{
	int	temp;
	int	i;

	temp = src->stack[0];
	src->size--;
	i = 0;
	while (i < src->size)
	{
		src->stack[i] = src->stack[i + 1];
		i++;
	}
	dest->size++;
	i = dest->size;
	while (i)
	{
		dest->stack[i] = dest->stack[i - 1];
		i--;
	}
	dest->stack[0] = temp;
	// i = 0;
	// while (i < src->size)
	// 	ft_printf("%d\n", src->stack[i++]);
	ft_printf("%s\n", instruction);
}

void	swap(int *stack, char *instruction)
{
	int	temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
	ft_printf("%s\n", instruction);
}

void	rotate(t_stack *stack, char *instruction)
{
	int	temp;
	int	i;

	temp = stack->stack[0];
	i = 0;
	while (i < stack->size)
	{
		stack->stack[i] = stack->stack[i + 1];
		i++;
	}
	stack->stack[i] = temp;
	// i = 0;
	// while (i < stack->size)
	// 	ft_printf("%d\n", stack->stack[i++]);
	ft_printf("%s\n", instruction);
}

void	reverse_rotate(t_stack *stack, char *instruction)
{
	int	temp;
	int	i;

	temp = stack->stack[stack->size - 1];
	i = stack->size - 1;
	while (i)
	{
		stack->stack[i] = stack->stack[i - 1];
		i--;
	}
	stack->stack[i] = temp;
	// i = 0;
	// while (i < stack->size)
	// 	ft_printf("%d\n", stack->stack[i++]);
	ft_printf("%s\n", instruction);
}
