/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:27:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/05 17:59:14 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
#include <stdlib.h>

// static void order_last_three(t_stack * a)
// {
// 	if (a->array[0] > a->array[1] && a->array[1] > a->array[2])
// 		rn(a, TRUE);
// 	else if (a->array[2] < a->array[1] && a->array[2] > a->array[0])
// 		rrn(a, TRUE);
// 	else if (a->array[0] > a->array[1] && a->array[0] > a->array[2])
// 		rn(a, TRUE);
// 	else if (a->array[2] < a->array[0] && a->array[2] < a->array[1])
// 		rrn(a, TRUE);
// 	if (a->array[0] > a->array[1])
// 		sn(a, TRUE);
// }

// static void get_back(t_stack * a, t_stack * b)
// {
// 	int moves_b;
// 	int i;

// 	moves_b = 0;
// 	while (b->length > 0)
// 	{
// 		i = 0;
// 		moves_b = get_bigger_pos(a, b->array[0]);
// 		if (moves_b > (a->length / 2))
// 			while (i++ < (a->length - moves_b))
// 				rrn(a, TRUE);
// 		else
// 			while (i++ < moves_b)
// 				rn(a, TRUE);
// 		pn(b, a);
// 		if (a->array[0] > a->array[1])
// 			sn(a, TRUE);
// 	}
// }

static void put_on_top(t_stack * n, int number)
{
	int pos_n;
	int i;

	i = 0;
	pos_n = get_pos(n, number);
	if (pos_n > 0)
	{
		if (pos_n > (n->length / 2))
			while (i++ < (n->length - pos_n))
				rrn(n, TRUE);
		else
			while (i++ < pos_n)
				rn(n, TRUE);
	}
}

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
	int	  chunk_start, chunk_end;

	if (a->length <= 100)
		chunk_size = 20;
	else
		chunk_size = 45;
	sorted = get_sorted_array(a);

	chunk_start = 0;
	while (chunk_start < a->length)
	{
		chunk_end = chunk_start + chunk_size;
		if (chunk_end > a->length)
			chunk_end = a->length;

		int i = 0;
		int count = 0;
		int len = a->length;
		while (i < len && count < (chunk_end - chunk_start))
		{
			int val = a->array[0];
			if (val >= sorted[chunk_start] && val < sorted[chunk_end])
			{
				pn(a, b); // pb
				count++;
			}
			else
				rn(a, TRUE); // ra
			i++;
		}
		chunk_start = chunk_end;
	}
	free(sorted);

	// Agora traga de volta para a, sempre o maior de b
	while (b->length > 0)
	{
		int max = get_bigger(b);
		int pos = get_pos(b, max);
		if (pos <= b->length / 2)
			while (get_pos(b, max) != 0)
				rn(b, TRUE); // rb
		else
			while (get_pos(b, max) != 0)
				rrn(b, TRUE); // rrb
		pn(b, a);			  // pa
	}
	put_on_top(a, get_smaller(a));
}
