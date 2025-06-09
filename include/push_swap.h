/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:38:54 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/09 19:11:46 by dximenes         ###   ########.fr       */
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
	int * better;
	int	  better_len;
	int	  total;
} t_moves;

typedef struct s_stack
{
	char * name;
	int *  array;
	int	   length;
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

// helpers
int *	better_array(t_stack * a, t_moves *moves);
t_moves calc_moves(t_stack * a, t_stack * b, int number);
int		fh_issrted(t_stack * a, t_stack * b);
int		get_bigger_pos(t_stack * b, int number);
int		get_smaller_pos(t_stack * b, int number);
int		get_smaller(t_stack * n);
int		get_bigger(t_stack * n);
int		get_pos(t_stack * n, int number);
#endif