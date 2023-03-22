/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:46:06 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/22 18:48:46 by aaugu            ###   ########.fr       */
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
int		init_stacks(t_game *game);

/* ---------------	SOLVER AND UTILS	--------------- */
void	solve(t_stack *a, t_stack *b);

int		get_min(int *list, int size);
void	get_min_max(int *list, int size, int *min, int *max);

int		*get_costs(t_stack *a, t_stack *b);
int		get_pos_b(t_stack *b, int value);

/* ---------------	SORTING METHODS	--------------- */
void	sort_three(t_stack *a);
void	sort_small(t_stack *a, t_stack *b);
void	sort_big(t_stack *a, t_stack *b);

/* ---------------	INSTRUCTIONS	--------------- */
void	push(t_stack *src, t_stack *dest, char *instruction);
void	swap(int *stack, char *instruction);
void	rotate(t_stack *stack, char *instruction);
void	reverse_rotate(t_stack *stack, char *instruction);

/* ---------------	ENDGAME UTILS	--------------- */
void	error(char *error);

#endif
