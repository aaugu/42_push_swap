/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:49:38 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/14 13:06:25 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void push(t_stack src, t_stack dest, char *instruction)
{
	int	temp;
	int	i;

	temp = src.content[0];
	src.size--;
	i = 0;
	while (i < src.size)
	{
		src.content[i] = src.content[i + 1];
		i++;
	}
	i = 0;
	dest.size++;
	while (i)
	{
		dest.content[i] = dest.content[i - 1];
		i--;
	}
	dest.content[0] = temp;
	ft_printf("%s\n", instruction);
}

void swap(int *stack, char *instruction)
{
	int temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
	ft_printf("%s\n", instruction);
}

void rotate(t_stack stack, char *instruction)
{
	int temp;
	int i;

	temp = stack.content[0];
	i = 0;
	while (i < stack.size)
	{
		stack.content[i] = stack.content[i + 1];
		i++;
	}
	stack.content[i] = temp;
	ft_printf("%s\n", instruction);
}

void reverse_rotate(t_stack stack, char *instruction)
{
	int temp;
	int i;

	temp = stack.content[stack.size];
	i = stack.size;
	while (i)
	{
		stack.content[i] = stack.content[i - 1];
		i--;
	}
	stack.content[i] = temp;
	ft_printf("%s\n", instruction);
}
