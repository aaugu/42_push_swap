/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 08:17:49 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/14 10:14:08 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**get_args(char **argv, int argc)
{
	if (argc == 1)
	{
		ft_printf("Error\nWrong number of arguments.\n");
		return (NULL);
	}
	else if (argc == 2)
		return (ft_split(argv[1], ' '));
	else
		return (parse_args(&argv[1], argc));
}

char	**parse_args(char **input, int size)
{
	char	**list;
	int		i;

	list = (char **)malloc(sizeof(char *) * (size - 1));
	if (!list)
		return (NULL);
	list[size - 2] = NULL;
	i = 0;
	while (i < size)
	{
		list[i] = ft_strdup(input[j]);
		if (!list[i++])
		{
			ft_strs_free(list, size);
			return (NULL);
		}
	}
	return (list);
}
