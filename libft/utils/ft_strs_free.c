/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_dptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:54:47 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/10 10:20:50 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_strs_free(char **strs, int size)
{
	int	i;

	i = 0;
	while (i < size && strs[i])
		free(strs[i++]);
	free(strs);
}
