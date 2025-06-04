/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pn.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:38:09 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/04 15:01:59 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void pn(t_stack * from, t_stack * to)
{
	int temp;
	int i;

	temp = from->array[0];
	i = -1;
	while (++i < from->length)
		from->array[i] = from->array[i + 1];
	from->length--;
	i = (to->length++) + 1;
	while (--i > 0)
		to->array[i] = to->array[i - 1];
	to->array[0] = temp;
	ft_putstr_fd("p", 1);
	ft_putendl_fd(to->name, 1);
}
