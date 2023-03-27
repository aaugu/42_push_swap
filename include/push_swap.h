/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:46:06 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/27 14:19:19 by aaugu            ###   ########.fr       */
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
	int		median;
}			t_game;

# define PRINT_INT(x) ft_printf("%d\n", x);

void	print_stack(t_stack *stack, char *suffix);

/* ---------------	PARSE INPUT	--------------- */
char	**get_input(char **argv, int argc);

/* ---------------	CHECKS	--------------- */
t_bool	is_list_valid(char **list, int size);

/* ---------------	INIT	--------------- */
int		init_stacks(t_game *game);

/* ---------------	SOLVER AND MIN MAX UTILS	--------------- */
void	solve(t_game *game);

int		get_first_min(int *list, int size);
int		get_min(int *list, int size);
int		get_max(int *list, int size);

/* ---------------	SORTING METHODS	--------------- */
void	sort_three(t_stack *a);
void	sort_small(t_stack *a, t_stack *b);
void	sort_big(t_stack *a, t_stack *b, int median);

/* ---------------	SORTING BIG UTILS	--------------- */
int		*get_costs(t_stack *a, t_stack *b);
int		cost_move_top(t_stack *stack, int pos);
t_bool	is_at_begin(int pos, int size);

/* ---------------	MOVES UTILS	--------------- */
void	move_pos_top(t_stack *a, t_stack *b);
void	move_top_one(t_stack *stack, char pile);

/* ---------------	POSITION UTILS	--------------- */
int		get_pos_a(t_stack *a, int nb_b, int b_max);
int		get_value_pos(t_stack *stack, int value);
int		get_target_pos_a(t_stack *a, int nb_b);

/* ---------------	INSTRUCTIONS	--------------- */
void	push(t_stack *src, t_stack *dest, char *instruction);
void	swap(int *stack, char *instruction);
void	rotate(t_stack *stack, char *instruction);
void	reverse_rotate(t_stack *stack, char *instruction);

#endif