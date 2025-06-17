/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sn.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:42:43 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/17 21:00:13 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void sn(t_stack * n, int toprint)
{
	int temp;

	if (n && n->len > 1)
	{
		temp = n->array[0];
		n->array[0] = n->array[1];
		n->array[1] = temp;
	}
	if (toprint)
	{
		ft_putstr_fd("s", 1);
		ft_putendl_fd(n->name, 1);
	}
}
