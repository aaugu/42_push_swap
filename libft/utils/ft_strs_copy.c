/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:55:09 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/10 10:48:58 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	**ft_strs_copy(const char **src, int size)
{
	int		i;
	char	**dest;

	i = 0;
	dest = (char **)malloc(sizeof(char *) * (size + 1));
	if (!dest)
		return (NULL);
	dest[size] = NULL;
	while (i < size)
	{
		dest[i] = ft_strdup(src[i]);
		if (!dest[i++])
		{
			ft_strs_free(dest, size);
			return (NULL);
		}
	}
	return (dest);
}
