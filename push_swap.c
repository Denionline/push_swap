/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:27:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/22 12:42:10 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void	fh_ordernodes(t_node **a, t_node **b)
{
	t_list	*current;

	current = (*a)->top;
	while (current->next)
	{
		if (current->number > current->next->number)
			ft_rn(a);
		else if (current->next && (*a)->top->number > (*a)->bottom->number)
			ft_rrn(a);
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
		if (current->next && (*b)->top->number < (*b)->top->next->number)
			ft_rn(b);
		else if (current->next && (*b)->top->number < (*b)->bottom->number)
			ft_rrn(b);
		else
		{
			ft_pn(b, a);
			if ((*a)->top->number > (*a)->top->next->number)
				ft_sn(a);
		}
		current = (*b)->top;
	}
}

static int	fh_checkorder(t_list *lst)
{
	// ft_putendl_fd("--------------------------------------------", 1);
	while (lst->next)
	{
		if (lst->number > lst->next->number)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	push_swap(t_node **a, t_node **b)
{
	while (fh_checkorder((*a)->top))
		fh_ordernodes(a, b);
}
