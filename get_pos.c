/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:37:08 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/28 18:16:42 by dximenes         ###   ########.fr       */
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

	if (searchbetween)
		number = get_lesser(n, number);
	pos = -1;
	while (++pos < n->length)
		if (n->array[pos] == number)
			break;
	return (pos);
}

	// bigger = n->array[0];
	// i = 0;
	// while (i < n->length)
	// {
	// 	if (n->array[i] > bigger)
	// 		bigger = n->array[i];
	// 	i++;
	// }
	// lesser = bigger;
	// i = 0;
	// while (i < n->length)
	// {
	// 	if (n->array[i] < lesser && n->array[i] > number)
	// 		lesser = n->array[i];
	// 	i++;
	// }