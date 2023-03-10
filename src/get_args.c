/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 08:17:49 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/10 12:05:19 by aaugu            ###   ########.fr       */
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
		return (parse_args(argv));
}

char	**parse_args(char **input)
{
	char	**list;
	int		size;
	int		i;
	int		j;

	size = ft_strs_len(input);
	list = (char **)malloc(sizeof(char *) * (size));
	if (!list)
		return (NULL);
	list[size] = NULL;
	i = 0;
	j = 1;
	while (j < size)
	{
		list[i] = ft_strdup(input[j]);
		if (!list[i++])
		{
			ft_strs_free(list, size);
			return (NULL);
		}
		j++;
	}
	return (list);
}
