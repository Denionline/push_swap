/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:38:54 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/13 15:18:57 by dximenes         ###   ########.fr       */
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
	int * best_seq;
	int	  best_seq_len;
	int	  total;
} t_moves;

typedef struct s_stack
{
	char * name;
	int *  array;
	int	   len;
} t_stack;

int	 main(int argc, char * argv[]);
void push_swap(t_stack * a, t_stack * b);

// Utils
void rotate_one(t_stack * a, t_stack * b, t_moves * moves);
void rotate_two(t_stack * a, t_stack * b, t_moves * moves);

// Operations
void pn(t_stack * from, t_stack * to);
void sn(t_stack * n, int toprint);
void rn(t_stack * n, int toprint);
void rrn(t_stack * n, int toprint);
void ss(t_stack * a, t_stack * b);
void rr(t_stack * a, t_stack * b);
void rrr(t_stack * a, t_stack * b);

// calc_moves.c
t_moves calc_moves(t_stack * a, t_stack * b, int number);
int		fh_issrted(t_stack * a, t_stack * b);
int *	find_lis_sequence(int * array, int len, int * lis_len);
//get_number.c
int		get_bigger(t_stack * n);
int		get_smaller(t_stack * n);
int		get_pos(t_stack * n, int number);
#endif