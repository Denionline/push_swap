/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:38:09 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/20 12:50:26 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_pn(t_node **from, t_node **to)
{
	t_list	*topfrom;
	t_list	*topto;

	topfrom = (*from)->top;
	(*from)->top = topfrom->next;
	topto = (*to)->top;
	topfrom->next = topto;
	(*to)->top = topfrom;
	ft_putchar_fd('p', 1);
	ft_putendl_fd((*to)->name, 1);
}