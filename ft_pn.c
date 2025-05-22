/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:38:09 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/22 11:26:18 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void ft_pn(t_node ** from, t_node ** to)
{
	t_list * tomovefrom;

	tomovefrom = (*from)->top;

	if ((*from)->top->next)
	{
		(*from)->top = (*from)->top->next;
		(*from)->top->prev = NULL;
	}
	else
	{
		(*from)->top = NULL;
		(*from)->bottom = NULL;
	}

	if ((*to)->top != NULL)
	{
		tomovefrom->next = (*to)->top;
		(*to)->top->prev = tomovefrom;
		(*to)->top = tomovefrom;
	}
	else
	{
		tomovefrom->next = NULL;
		tomovefrom->prev = NULL;
		(*to)->top = tomovefrom;
		(*to)->bottom = tomovefrom;
	}


	ft_putstr_fd("p", 1);
	ft_putendl_fd((*to)->name, 1);
}
