/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:38:54 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/19 00:08:58 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/include/libft.h"

typedef struct s_node
{
	size_t	index;
	int		number;
	t_list	*top;
	t_list	*bottom;
}	t_node;

int		main(int argc, char *argv[]);
int		push_swap(char *n);

//Operations
void	ft_sa(void);
void	ft_sb(void);
void	ft_pa(void);
void	ft_pb(void);
void	ft_ra(void);
void	ft_rb(void);
void	ft_rra(void);
void	ft_rrb(void);


#endif