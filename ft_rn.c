/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:52:52 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/22 11:12:53 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void ft_rn(t_node ** n)
{
	t_list	*tomove;

	tomove = (*n)->top;
	(*n)->top = (*n)->top->next;
	(*n)->top->prev = NULL;
	tomove->prev = (*n)->bottom;
	(*n)->bottom->next = tomove;
	(*n)->bottom = tomove;
	(*n)->bottom->next = NULL;

	ft_putstr_fd("r", 1);
	ft_putendl_fd((*n)->name, 1);
}
