/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:46:06 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/24 12:00:56 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

/* ---------------	TYPEDEF	--------------- */
typedef struct s_stack
{
	int	*stack;
	int	size;
	int	pos;
	int	move;
	int	min;
	int	max;
}		t_stack;

typedef struct s_game
{
	t_stack	a;
	t_stack	b;
	char	**list;
	int		size;
}			t_game;

/* ---------------	PARSE INPUT	--------------- */
char	**get_input(char **argv, int argc);

/* ---------------	CHECKS	--------------- */
t_bool	is_list_valid(char **list, int size);

/* ---------------	INIT	--------------- */
int		init_stacks(char **list, int size, t_stack *a, t_stack *b);

/* ---------------	SOLVER AND MIN MAX UTILS	--------------- */
void	solve(t_stack *a, t_stack *b);

int		get_first_min(int *list, int size);
int		get_min(int *list, int size);
int		get_max(int *list, int size);

/* ---------------	SORTING METHODS	--------------- */
void	sort_three(t_stack *a);
void	sort_small(t_stack *a, t_stack *b);
void	sort_big(t_stack *a, t_stack *b);

/* ---------------	SORTING BIG UTILS	--------------- */
int		*get_costs(t_stack *a, t_stack *b);
int		cost_move_top(t_stack *stack, int pos);

/* ---------------	MOVES UTILS	--------------- */
void	move_pos_top(t_stack *a, t_stack *b);
void	move_top_one(t_stack *stack, char pile);

/* ---------------	POSITION UTILS	--------------- */
int		get_pos_b(t_stack *b, int value);
t_bool	is_same_pos(int pos_a, int pos_b, int size_a, int size_b);
t_bool	is_at_begin(int pos, int size);
void	change_pos(t_stack *stack, char *instruction);

/* ---------------	INSTRUCTIONS	--------------- */
void	push(t_stack *src, t_stack *dest, char *instruction);
void	swap(int *stack, char *instruction);
void	rotate(t_stack *stack, char *instruction);
void	reverse_rotate(t_stack *stack, char *instruction);

#endif
