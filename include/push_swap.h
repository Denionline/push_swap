/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:38:54 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/13 18:34:38 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/include/libft.h"

#define TRUE 1
#define FALSE 0

typedef struct s_moves
{
	int	  a;
	int	  b;
	int	  reverse_a;
	int	  reverse_b;
	int * sequence;
	int	  sequence_len;
	int	  total;
} t_moves;

typedef struct s_stack
{
	char * name;
	int *  array;
	int	   len;
} t_stack;

// push_swap.c
int		main(int argc, char * argv[]);

// rotates.c
void	rotate_one(t_stack * a, t_stack * b, t_moves * moves);
void	rotate_two(t_stack * a, t_stack * b, t_moves * moves);

// operations
void	pn(t_stack * from, t_stack * to);
void	sn(t_stack * n, int toprint);
void	rn(t_stack * n, int toprint);
void	rrn(t_stack * n, int toprint);
void	ss(t_stack * a, t_stack * b);
void	rr(t_stack * a, t_stack * b);
void	rrr(t_stack * a, t_stack * b);

// sort.c
void	sort(t_stack * a, t_stack * b);

// parse.c
void	parse(t_stack **a, t_stack **b, char **args, int length);

// calc_moves.c
t_moves	calc_moves(t_stack * a, t_stack * b, int number);
// find_lis_sequence.c
void	ft_find_lis_sequence(int * array, int len, t_moves *moves);
// get_number.c
int		get_bigger(t_stack * n);
int		get_smaller(t_stack * n);
int		get_pos(t_stack * n, int number);
#endif