/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:12:55 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/13 23:20:19 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

size_t get_pos(t_stack * n, size_t number)
{
	size_t	pos;

	pos = 0;
	while (pos < n->len)
	{
		if (n->array[pos] == number)
			return (pos);
		pos++;
	}
	return (-1);
}

size_t get_bigger(t_stack * n)
{
	size_t	bigger;
	size_t	pos;

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
size_t get_smaller(t_stack * n)
{
	size_t	smaller;
	size_t	pos;

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