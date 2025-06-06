/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:27:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/06 12:29:03 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
#include <stdlib.h>

static int * get_sorted_array(t_stack * a)
{
	int * sorted = malloc(a->length * sizeof(int));
	for (int i = 0; i < a->length; i++)
		sorted[i] = a->array[i];
	for (int i = 0; i < a->length - 1; i++)
		for (int j = 0; j < a->length - i - 1; j++)
			if (sorted[j] > sorted[j + 1])
			{
				int tmp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = tmp;
			}
	return sorted;
}

void push_swap(t_stack * a, t_stack * b)
{
	int	  chunk_size;
	int * sorted;
	int	  chunk_start;
	int	  chunk_end;
	int	  val;
	int	  max;
	int	  pos;
	int	  i;
	int	  found;
	int	  j;
	int	  total_len;

	total_len = a->length;
	if (total_len <= 100)
		chunk_size = 15;
	else
		chunk_size = 45;
	sorted = get_sorted_array(a);

	chunk_start = 0;
	while (chunk_start < total_len)
	{
		chunk_end = chunk_start + chunk_size;
		if (chunk_end > total_len)
			chunk_end = total_len;

		found = 1;
		while (found && a->length > 0)
		{
			found = 0;
			j = 0;
			while (j < a->length)
			{
				val = a->array[j];
				if (val >= sorted[chunk_start] && val < sorted[chunk_end])
				{
					found = 1;
					break;
				}
				j++;
			}
			if (!found)
				break;
			val = a->array[0];
			if (val >= sorted[chunk_start] && val < sorted[chunk_end])
			{
				pn(a, b);
				if (val < sorted[chunk_start] + (chunk_end - chunk_start) / 2)
					rn(b, TRUE);
			}
			else
				rn(a, TRUE);
		}
		chunk_start = chunk_end;
	}
	free(sorted);

	while (a->length > 0)
		pn(a, b);

	while (b->length > 0)
	{
		max = get_bigger(b);
		pos = get_pos(b, max);
		if (pos <= b->length / 2)
		{
			i = 0;
			while (get_pos(b, max) != 0 && i++ < b->length)
				rn(b, TRUE);
		}
		else
		{
			i = 0;
			while (get_pos(b, max) != 0 && i++ < b->length)
				rrn(b, TRUE);
		}
		pn(b, a);
	}
}
