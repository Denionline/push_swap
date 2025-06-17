/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:12:55 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/17 09:29:44 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

long get_pos(t_stack * n, long number)
{
	long	pos;

	pos = 0;
	while (pos < n->len)
	{
		if (n->array[pos] == number)
			return (pos);
		pos++;
	}
	return (-1);
}

long get_bigger(t_stack * n)
{
	long	bigger;
	long	pos;

	bigger = n->array[0];
	pos = 0;
	while (pos < n->len)
	{
		if (n->array[pos] > bigger)
			bigger = n->array[pos];
		pos++;
	}
	return (bigger);
}
long get_smaller(t_stack * n)
{
	long	smaller;
	long	pos;

	smaller = n->array[0];
	pos = 0;
	while (pos < n->len)
	{
		if (n->array[pos] < smaller)
			smaller = n->array[pos];
		pos++;
	}
	return (smaller);
}