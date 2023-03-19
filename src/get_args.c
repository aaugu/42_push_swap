/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 08:17:49 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/19 19:11:34 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**get_args(char **argv, int argc)
{
	char	**list;

	if (argc == 1)
		return (NULL);
	else if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		if (!list)
			return NULL;
	}
	else
	{
		list = parse_args(&argv[1], (argc - 1));
		if (!list)
			return NULL;
	}
	return (list);
}

char	**parse_args(char **input, int size)
{
	char	**list;
	int		i;

	list = (char **)malloc(sizeof(char *) * (size + 1));
	if (!list)
		return (NULL);
	list[size] = NULL;
	i = 0;
	while (i < size)
	{
		list[i] = ft_strdup(input[i]);
		if (!list[i++])
		{
			ft_strs_free(list, size);
			return (NULL);
		}
	}
	return (list);
}
