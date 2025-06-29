/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rn.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:17:20 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/17 09:29:44 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void rn(t_stack * n, int toprint)
{
	long tomove;
	long i;

	if (n->len <= 1)
		return;
	tomove = n->array[0];
	i = 0;
	while (i < n->len - 1)
	{
		n->array[i] = n->array[i + 1];
		i++;
	}
	n->array[n->len - 1] = tomove;
	if (toprint)
	{
		ft_putstr_fd("r", 1);
		ft_putendl_fd(n->name, 1);
	}
}
