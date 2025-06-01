/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:37:08 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/29 12:11:47 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static int get_lesser(t_stack * n, int number)
{
	int bigger;
	int lesser;
	int i;

	lesser = n->array[0];
	i = -1;
	while (++i < n->length)
	{
		if (n->array[i] < lesser)
			lesser = n->array[i];
	}
	bigger = lesser;
	i = -1;
	while (++i < n->length)
	{
		if (n->array[i] > bigger && n->array[i] < number)
			bigger = n->array[i];
	}
	return (bigger);
}

int get_pos(t_stack * n, int number, int searchbetween)
{
	int pos;
	int	newpos;

	newpos = number;
	if (searchbetween)
		newpos = get_lesser(n, number);
	pos = 0;
	while (pos < n->length)
	{
		if (n->array[pos] == newpos)
			break ;
		pos++;
	}
	if (number < newpos && pos == (n->length - 1))
		return (0);
	return (pos);
}
