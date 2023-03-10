/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:46:06 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/10 10:30:39 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

typedef struct s_game
{
	t_list	pile_a;
	t_list	pile_b;
	char	**list;
	int		list_size;
	int		size_a;
	int		size_b;
	int		min;
	int		max;
}			t_game;

char	**get_args(char **input, int nb);
char	**parse_args(char **input);

#endif
