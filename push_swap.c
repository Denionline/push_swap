/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:27:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/21 18:02:49 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void push_swap(t_node ** a, t_node ** b)
{
	t_list *current;

	current = (*a)->top;
	while (current->next)
	{
		if (current->number > current->next->number)
			ft_rn(a);
		else
		{
			ft_pn(a, b);
			if ((*b)->top->next)
			{
				if ((*b)->top->number < (*b)->top->next->number)
				{
					ft_rn(b);
				}
			}
		}
		current = (*a)->top;
	}
	current = (*b)->top;
	while (current != NULL)
	{
		if (current->next && current->number < current->next->number)
			ft_sn(b);
		if (current->next && (*b)->top->number < (*b)->bottom->number)
			ft_rrn(b);
		ft_pn(b, a);
		if ((*a)->top->number > (*a)->top->next->number)
			ft_sn(a);
		current = (*b)->top;
	}
}
