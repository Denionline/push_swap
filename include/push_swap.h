/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:38:54 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/20 13:56:59 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdio.h"
# include "libft/include/libft.h"

typedef struct s_node
{
	char	*name;
	size_t	length;
	t_list	*top;
	t_list	*bottom;
}	t_node;

int		main(int argc, char *argv[]);
void	push_swap(t_node **a, t_node **b);

//Operations
void	ft_sn(t_node **n);
void	ft_pn(t_node **from, t_node **to);
void	ft_rn(t_node **n);
void	ft_rrn(t_node **n);


#endif