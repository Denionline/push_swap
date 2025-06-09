/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:27:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/09 18:35:40 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
#include <stdlib.h>

static void order_last_three(t_stack * a)
{
	if (a->array[0] > a->array[1] && a->array[1] > a->array[2])
		rn(a, TRUE);
	else if (a->array[2] < a->array[1] && a->array[2] > a->array[0])
		rrn(a, TRUE);
	else if (a->array[0] > a->array[1] && a->array[0] > a->array[2])
		rn(a, TRUE);
	else if (a->array[2] < a->array[0] && a->array[2] < a->array[1])
		rrn(a, TRUE);
	if (a->array[0] > a->array[1])
		sn(a, TRUE);
}

static void get_back(t_stack * a, t_stack * b)
{
	int moves_b;
	int i;

	moves_b = 0;
	while (b->length > 0)
	{
		i = 0;
		moves_b = get_bigger_pos(a, b->array[0]);
		if (moves_b > (a->length / 2))
			while (i++ < (a->length - moves_b))
				rrn(a, TRUE);
		else
			while (i++ < moves_b)
				rn(a, TRUE);
		pn(b, a);
		if (a->array[0] > a->array[1])
			sn(a, TRUE);
	}
}

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

// Helper: copy and sort the array
static int * get_sorted_array(t_stack * a)
{
	int * sorted = malloc(a->length * sizeof(int));
	for (int i = 0; i < a->length; i++)
		sorted[i] = a->array[i];
	return sorted;
}

static int in_chunk(int value, int * sorted, int start, int end)
{
	return (value >= sorted[start] && value < sorted[end]);
}

void push_swap(t_stack * a, t_stack * b)
{
	int	  chunk_count = 11;
	int * sorted = get_sorted_array(a);
	int	  chunk_size = a->length / chunk_count;
	int	  chunk_start, chunk_end;

	for (int c = 0; c < chunk_count && a->length > 3; c++)
	{
		chunk_start = c * chunk_size;
		chunk_end = (c == chunk_count - 1) ? a->length : (c + 1) * chunk_size;
		int found_in_chunk;
		do
		{
			found_in_chunk = 0;
			t_moves best_moves;
			int		found = 0;
			for (int i = 0; i < a->length; i++)
			{
				if (in_chunk(a->array[i], sorted, chunk_start, chunk_end))
				{
					t_moves moves = calc_moves(a, b, a->array[i]);
					if (!found || moves.total < best_moves.total)
					{
						best_moves = moves;
						found = 1;
						found_in_chunk = 1;
					}
				}
			}
			if (found && a->length > 3)
			{
				if (best_moves.reverse_a == best_moves.reverse_b)
					rotate_two(a, b, &best_moves);
				rotate_one(a, b, &best_moves);
				pn(a, b);
			}
		} while (found_in_chunk && a->length > 3);
	}
	while (a->length > 3)
	{
		t_moves best_moves;
		int		found = 0;
		for (int i = 0; i < a->length; i++)
		{
			t_moves moves = calc_moves(a, b, a->array[i]);
			if (!found || moves.total < best_moves.total)
			{
				best_moves = moves;
				found = 1;
			}
		}
		if (found)
		{
			if (best_moves.reverse_a == best_moves.reverse_b)
				rotate_two(a, b, &best_moves);
			rotate_one(a, b, &best_moves);
			pn(a, b);
		}
	}
	free(sorted);
	order_last_three(a);
	get_back(a, b);
	put_on_top(a, get_smaller(a));
}
