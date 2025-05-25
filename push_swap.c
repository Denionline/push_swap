/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:27:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/25 15:51:41 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	push_swap(t_stack **a, t_stack **b)
{
	int	lessn;
	int	lesspos;
	int	len;
	int	diff;
	int	i;

	ft_pn(a, b);
	ft_pn(a, b);
	if ((*b)->array[0] < (*b)->array[1])
	ft_sn(b);
	while ((*a)->length > 0)
	{
		len = (*a)->length;
		lesspos = 0;
		lessn = (*a)->array[0];
		i = 0;
		while (i < len)
		{
			if ((*a)->array[i] < lessn)
			{
				lessn = (*a)->array[i];
				lesspos = i;
			}
			i++;
		}
		diff = (len - lesspos);
		if (lesspos > ((*a)->length / 2))
			while (diff-- > 0)
				ft_rrn(a);
		else
			while (lesspos-- > 0)
				ft_rn(a);
		if ((*a)->array[0] > (*b)->array[0])
			ft_pn(a, b);
		else if ((*a)->array[0] < (*b)->array[(*b)->length - 1])
		{
			ft_pn(a, b);
			ft_rn(b);
		}
		else
		{
			ft_pn(a, b);
			ft_sn(b);
		}
	}
}
