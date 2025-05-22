/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:44:06 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/22 11:18:39 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_rrn(t_node **n)
{
	t_list	*tomove;

	tomove = (*n)->bottom;
	(*n)->bottom = (*n)->bottom->prev;
	(*n)->bottom->next = NULL;
	(*n)->top->prev = tomove;
	tomove->next = (*n)->top;
	tomove->prev = NULL;
	(*n)->top = tomove;

	ft_putstr_fd("rr", 1);
	ft_putendl_fd((*n)->name, 1);
}