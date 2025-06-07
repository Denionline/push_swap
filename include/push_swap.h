/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:38:54 by dximenes          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/06/01 23:13:59 by dximenes         ###   ########.fr       */
=======
/*   Updated: 2025/06/06 14:32:57 by dximenes         ###   ########.fr       */
>>>>>>> cheap
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
	int reverse_a;
	int reverse_b;
	int total;
} t_moves;

typedef struct s_stack
{
	char * name;
	int *  array;
	int	   length;
} t_stack;

int	 main(int argc, char * argv[]);
void push_swap(t_stack * a, t_stack * b);

<<<<<<< HEAD
//Operations
void	sn(t_stack **n, int toprint);
void	ss(t_stack **a, t_stack **b, int toprint);
void	pn(t_stack *from, t_stack *to, int toprint);
void	rn(t_stack **n, int toprint);
void	rr(t_stack **a, t_stack **b, int toprint);
void	rrn(t_stack **n, int toprint);
void	rrr(t_stack **a, t_stack **b, int toprint);
=======
//Utils
void rotate_one(t_stack * a, t_stack * b, t_moves * moves);
void rotate_two(t_stack * a, t_stack * b, t_moves * moves);
>>>>>>> cheap

// Operations
void pn(t_stack * from, t_stack * to);
void sn(t_stack * n, int toprint);
void rn(t_stack * n, int toprint);
void rrn(t_stack * n, int toprint);
void ss(t_stack * a, t_stack * b);
void rr(t_stack * a, t_stack * b);
void rrr(t_stack * a, t_stack * b);

// helpers
t_moves calc_moves(t_stack * a, t_stack * b, int number);
int		fh_issrted(t_stack * a, t_stack * b);
int		get_bigger_pos(t_stack * b, int number);
int		get_smaller_pos(t_stack * b, int number);
int		get_smaller(t_stack * n);
int		get_bigger(t_stack * n);
int		get_pos(t_stack * n, int number);
#endif