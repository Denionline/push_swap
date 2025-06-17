/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrn.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:44:06 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/18 00:38:33 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrn(t_stack *n, int toprint)
{
	int	tomove;
	int	i;

	if (n && n->len > 0)
	{
		tomove = n->array[n->len - 1];
		i = n->len - 1;
		while (i > 0)
		{
			n->array[i] = n->array[i - 1];
			i--;
		}
		n->array[0] = tomove;
	}
	if (toprint)
	{
		ft_putstr_fd("rr", 1);
		ft_putendl_fd(n->name, 1);
	}
}
