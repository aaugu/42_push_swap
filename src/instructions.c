/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:49:38 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/14 12:00:46 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void push(t_stack src, t_stack dest, char *instruction)
{
	int	temp;
	int	i;

	temp = dest.content[0];
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

void rotate(int *stack, char *instruction)
{
}

void reverse_rotate(int *stack, char *instruction)
{
}
