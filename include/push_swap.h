/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:38:54 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/23 14:21:31 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdio.h"
# include "libft/include/libft.h"

typedef struct s_stack
{
	char	*name;
	int		*array;
	int		length;
}	t_stack;

int		main(int argc, char *argv[]);
void	push_swap(t_stack **a, t_stack **b);

//Operations
void	ft_sn(t_stack **n);
void	ft_pn(t_stack **from, t_stack **to);
void	ft_rn(t_stack **n);
void	ft_rrn(t_stack **n);

//helpers
void	fh_print(t_stack *a, t_stack *b, int amount);
#endif