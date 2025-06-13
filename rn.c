/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rn.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:17:20 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/13 15:18:57 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void rn(t_stack * n, int toprint)
{
	int tomove;
	int i;

	tomove = n->array[0];
	i = -1;
	while (++i < n->len)
		n->array[i] = n->array[i + 1];
	n->array[i - 1] = tomove;
	if (toprint)
	{
		ft_putstr_fd("r", 1);
		ft_putendl_fd(n->name, 1);
	}
}
