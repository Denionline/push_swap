/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:38:54 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/04 10:19:36 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/include/libft.h"
#include "stdio.h"

#define TRUE 1
#define FALSE 0

typedef struct s_moves
{
	int a;
	int b;
	int rr_a;
	int rr_b;
	int total;
} t_moves;

typedef struct s_stack
{
	char * name;
	int *  array;
	int	   length;
} t_stack;

int	 main(int argc, char * argv[]);
void push_swap(t_stack * a, t_stack * b, int print);

// Operations
void sn(t_stack * n, int toprint);
void ss(t_stack * a, t_stack * b, int toprint);
void pn(t_stack * from, t_stack * to, int toprint);
void rn(t_stack * n, int toprint);
void rr(t_stack * a, t_stack * b, int toprint);
void rrn(t_stack * n, int toprint);
void rrr(t_stack * a, t_stack * b, int toprint);

// helpers
t_moves calc_moves(t_stack * a, t_stack * b, int number);
void	fh_print(t_stack * a, t_stack * b, int amount);
int		fh_issrted(t_stack * a, t_stack * b);
int		get_bigger_pos(t_stack * b, int number);
int		get_smaller_pos(t_stack * b, int number);
int		get_smaller(t_stack * n);
int		get_bigger(t_stack * n);
int		get_pos(t_stack * n, int number);
#endif