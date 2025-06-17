/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pn.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:38:09 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/17 23:25:51 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print(char *name)
{
	ft_putstr_fd("p", 1);
	ft_putendl_fd(name, 1);
}

void pn(t_stack * from, t_stack * to, int toprint)
{
	long temp;
	long i;

	if (from && from->len > 0)
	{
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
	}
	if (toprint)
		print(to->name);
}
