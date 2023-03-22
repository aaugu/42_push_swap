/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:58:47 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/22 19:18:18 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_bool	list_is_num(char **list, int size);
t_bool	is_num(char *str);
t_bool	no_duplicate_num(char **list, int size);

t_bool	is_list_valid(char	**list, int size)
{
	if (list_is_num(list, size) == FALSE)
		return (0);
	if (no_duplicate_num(list, size) == FALSE)
		return (0);
	return (1);
}

t_bool	list_is_num(char **list, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (is_num(list[i]) == FALSE)
			return (0);
		i++;
	}
	return (1);
}

t_bool	is_num(char *str)
{
	char	*str_n;

	str_n = ft_itoa(ft_atoi(str));
	if (!str_n)
		return (0);
	if (!ft_strcmp(str, str_n))
	{
		free(str_n);
		return (1);
	}
	free(str_n);
	return (0);
}

t_bool	no_duplicate_num(char **list, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (!ft_strcmp(list[i], list[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
