/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:27:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/24 18:59:05 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	push_swap(t_stack **a, t_stack **b)
{
	int	lessn;
	int	lesspos;
	int	len;
	int	i;
	int	j;

	len = (*a)->length;
	ft_pn(a, b);
	ft_pn(a, b);
	while ((*a)->length > 0)
	{
		lesspos = 0;
		lessn = (*a)->array[0];
		i = 0;
		while (len--)
		{
			if ((*a)->array[i] < lessn)
			{
				lessn = (*a)->array[i];
				lesspos = i;
			}
			i++;
		}
		if (lesspos > ((*a)->length / 2))
		{
			j = lesspos - ((*a)->length / 2);
			while (j--)
				ft_rrn(a);
		}
		else if (lesspos < ((*a)->length / 2))
		{
			j = ((*a)->length / 2) - lesspos;
			while (j--)
				ft_rn(a);
		}
		else
		{
			j = lesspos + 1;
			while (j--)
				ft_rn(a);
		}
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
