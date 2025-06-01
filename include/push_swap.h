/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:38:54 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/01 23:13:59 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdio.h"
# include "libft/include/libft.h"

# define TRUE 1
# define FALSE 0

typedef struct s_stack
{
	char	*name;
	int		*array;
	int		length;
}	t_stack;

int		main(int argc, char *argv[]);
void	push_swap(t_stack *a, t_stack *b, int print);

//Operations
void	sn(t_stack **n, int toprint);
void	ss(t_stack **a, t_stack **b, int toprint);
void	pn(t_stack *from, t_stack *to, int toprint);
void	rn(t_stack **n, int toprint);
void	rr(t_stack **a, t_stack **b, int toprint);
void	rrn(t_stack **n, int toprint);
void	rrr(t_stack **a, t_stack **b, int toprint);

//helpers
int		calc_moves(t_stack * a, t_stack * b, int number);
int		get_pos(t_stack * n, int number, int searchbetween);
void	fh_print(t_stack *a, t_stack *b, int amount);
#endif