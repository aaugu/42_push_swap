/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:46:06 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/14 11:07:46 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

/* ---------------	TYPEDEF	--------------- */
typedef struct s_stack
{
	int *content;
	int size;
} t_stack;

typedef struct s_game
{
	t_stack a;
	t_stack b;
	char	**list;
	int		size;
	int		min;
	int		max;
}			t_game;

/* ---------------	PARSE INPUT	--------------- */
char	**get_args(char **argv, int argc);
char	**parse_args(char **input);

/* ---------------	CHECKS	--------------- */
t_bool 	is_list_valid(char **list, int size);
t_bool 	only_num(char **list, int size);
t_bool	is_num(char *str);
t_bool	no_duplicate_num(char **list, int size);

/* ---------------	GAME INIT	--------------- */
int		game_init(t_game game);
int		create_stack(t_stack stack, char **list, int l_size, int s_size);
void 	get_min_max(int *list, int size, int *min, int *max);

/* ---------------	SOLVER	--------------- */
	void game_solve(int **stack_a, int **stack_b, t_game game);
t_bool	is_stack_ordered(int *stack, int size);

/* ---------------	INSTRUCTIONS	--------------- */
void	push_a(int **a, int **b, t_game game);
void	push_b(int **a, int **b, t_game game);
int		*add_up(int *src, int to_add, int size);
int		*remove_up(int *list, int size);

void	swap(int **list, int size, t_game game);
void	rotate(int **list, int size, t_game game);
void	reverse_rotate(int **list, int size, t_game game);

/* ---------------	ENDGAME UTILS	--------------- */
void	game_clear(t_game game);

#endif
