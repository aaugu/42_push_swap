/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:48:33 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/22 18:53:54 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**parse_args(char **args, int size);

char	**get_input(char **argv, int argc)
{
	char	**list;

	if (argc == 2)
		list = ft_split(argv[1], ' ');
	else
		list = parse_args(&argv[1], (argc - 1));
	if (!list)
		return (NULL);
	return (list);
}

char	**parse_args(char **args, int size)
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
		list[i] = ft_strdup(args[i]);
		if (!list[i++])
		{
			ft_strs_free(list, size);
			return (NULL);
		}
	}
	return (list);
}
