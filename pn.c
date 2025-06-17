/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pn.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:38:09 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/17 09:29:44 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void pn(t_stack * from, t_stack * to)
{
	long temp;
	long i;

	if (from->len == 0)
		return;
	temp = from->array[0];
	i = 0;
	while (i < from->len - 1)
	{
		from->array[i] = from->array[i + 1];
		i++;
	}
	from->array[from->len - 1] = 0;
	from->len--;
	i = to->len;
	while (i > 0)
	{
		to->array[i] = to->array[i - 1];
		i--;
	}
	to->array[0] = temp;
	to->len++;

	ft_putstr_fd("p", 1);
	ft_putendl_fd(to->name, 1);
}
