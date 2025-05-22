/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:27:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/22 17:23:42 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void	fh_ordernodes(t_stack **a, t_stack **b)
{
	// fh_print(*a, *b);
	while ((*a)->length > 1)
	{
		if ((*a)->array[0] > (*a)->array[1])
			ft_rn(a);
		else
		{
			ft_pn(a, b);
			if ((*b)->array[0] < (*b)->array[1])
				ft_rn(b);
		}
		// fh_print(*a, *b);
	}
	while ((*b)->length > 0)
	{
		if ((*b)->array[0] < (*b)->array[1])
			ft_rn(b);
		else
		{
			ft_pn(b, a);
			if ((*a)->array[0] > (*a)->array[1])
				ft_sn(a);
		}
		// fh_print(*a, *b);
	}
}

void	push_swap(t_stack **a, t_stack **b)
{
	fh_ordernodes(a, b);
}
