/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:46:06 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/10 13:48:19 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

typedef struct s_game
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**list;
	int		l_size;
	int		size_a;
	int		size_b;
	int		min;
	int		max;
}			t_game;

char	**get_args(char **argv, int argc);
char	**parse_args(char **input);

t_bool	is_list_valid(t_game *game);
t_bool	only_num(char **list, int size);
t_bool	is_num(char *str);
t_bool	no_duplicate_num(char **list, int size);

void	delete_content(void *content);
void	clear_game(t_game *game);

#endif
