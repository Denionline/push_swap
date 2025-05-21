/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:38:09 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/21 18:41:16 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void ft_pn(t_node ** from, t_node ** to)
{
	t_list * tomoveto;
	t_list * tomovefrom;

	tomoveto = (*to)->top;
	tomovefrom = (*from)->top;

	(*to)->top = (*from)->top;
	(*from)->top = (*from)->top->next;

	

	ft_putstr_fd("p", 1);
	ft_putendl_fd((*to)->name, 1);
}