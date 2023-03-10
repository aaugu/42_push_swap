/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:46:06 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/10 15:05:31 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

/* ---------------	TYPEDEF	--------------- */
typedef struct s_lstnb
{
	int					nb;
	struct s_lstnb		*next;
}						t_lstnb;

typedef struct s_game
{
	t_lstnb	**stack_a;
	t_lstnb	**stack_b;
	char	**list;
	int		l_size;
	int		size_a;
	int		size_b;
	int		min;
	int		max;
}			t_game;

/* ---------------	PARSE INPUT	--------------- */
char	**get_args(char **argv, int argc);
char	**parse_args(char **input);

/* ---------------	CHECKS	--------------- */
t_bool	is_list_valid(t_game *game);
t_bool	only_num(char **list, int size);
t_bool	is_num(char *str);
t_bool	no_duplicate_num(char **list, int size);

/* ---------------	SOLVER	--------------- */
void	game_init(t_game *game);
void	create_stack_a(t_game *game);

/* ---------------	CHAINED LISTS UTILS	--------------- */
t_lstnb	*lstnew(int nb);
void	lstclear(t_lstnb **lst);

/* ---------------	ENDGAME UTILS	--------------- */
void	clear_game(t_game *game);

#endif
