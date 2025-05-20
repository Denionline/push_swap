/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:42:43 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/20 12:51:08 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_sn(t_node **n)
{
	
	t_list	*temp1;
	t_list	*temp2;

	temp1 = (*n)->top;
	temp2 = (*n)->top->next;

	temp1->prev = temp2;
	temp1->next = temp2->next;

	temp2->prev = NULL;
	temp2->next = temp1;
	(*n)->top = temp2;
	(*n)->top->next = temp1;
	ft_putchar_fd('s', 1);
	ft_putendl_fd((*n)->name, 1);
}
