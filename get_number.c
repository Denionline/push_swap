/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:12:55 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/13 15:42:33 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int get_pos(t_stack * n, int number)
{
	int	pos;

	pos = 0;
	while (pos < n->len)
	{
		if (n->array[pos] == number)
			return (pos);
		pos++;
	}
	return (-1);
}

int get_bigger(t_stack * n)
{
	int	bigger;
	int	pos;

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
int get_smaller(t_stack * n)
{
	int	smaller;
	int	pos;

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