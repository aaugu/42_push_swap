/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:46:06 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/22 12:04:25 by aaugu            ###   ########.fr       */
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
}		t_stack;

typedef struct s_game
{
	t_stack	a;
	t_stack	b;
	char	**list;
	int		*copy;
	int		size;
	int		med;
}			t_game;

/* ---------------	PARSE INPUT	--------------- */
char	**get_args(char **argv, int argc);
char	**parse_args(char **input, int size);

/* ---------------	CHECKS	--------------- */
t_bool	is_list_valid(char **list, int size);
t_bool	only_num(char **list, int size);
t_bool	is_num(char *str);
t_bool	no_duplicate_num(char **list, int size);

/* ---------------	GAME INIT	--------------- */
int		init_stacks(t_game *game);
int		*create_stack(char **list, int l_size, int s_size);
void	convert_int(char **list, t_stack *a);

/* ---------------	SOLVER	--------------- */
void	solve(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	sort_small(t_stack *a, t_stack *b);
void	sort_small_a(t_stack *a, t_stack *b);
void	sort_big(t_stack *a, t_stack *b);

void	get_min_max(int *list, int size, int *min, int *max);

/* ---------------	INSTRUCTIONS	--------------- */
void	push(t_stack *src, t_stack *dest, char *instruction);
void	swap(int *stack, char *instruction);
void	rotate(t_stack *stack, char *instruction);
void	reverse_rotate(t_stack *stack, char *instruction);

/* ---------------	ENDGAME UTILS	--------------- */
void	error(char *error);

#endif
