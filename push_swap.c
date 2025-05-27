/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:27:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/27 10:16:16 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static int get_pos(t_stack * n, int number)
{
	int pos;

	pos = -1;
	while (++pos < n->length)
		if (n->array[pos] == number)
			break;
	return (pos);
}

static int is_reverse(t_stack *n, int moves)
{
	if (moves > (n->length / 2))
		return (0);
	return (1);
}

static int calc_moves(t_stack * a, t_stack * b, int number)
{
	int less_number;
	int moves_a;
	int moves_b;
	int i;

	less_number = number;
	i = -1;
	while (++i < b->length)
		if (b->array[i] < less_number)
			less_number = b->array[i];
	moves_a = get_pos(a, number);
	moves_b = get_pos(b, less_number);
	if (is_reverse(a, moves_a))
		moves_a -= a->length;
	if (is_reverse(b, moves_b))
		moves_b -= b->length;
	if (is_reverse(a, moves_a) == is_reverse(b, moves_b))
	{
		if (moves_a > moves_b)
			return (moves_a - moves_b + 1);
		return (moves_b - moves_a + 1);
	}
	return (moves_a + moves_b + 1);
}

void push_swap(t_stack ** a, t_stack ** b, int print)
{
	int lesser;
	int lesser_pos;
	int lesser_moves;
	int i;

	pn(a, b, print);
	pn(a, b, print);
	while ((*a)->length > 3)
	{
		i = 0;
		lesser = (*a)->array[i];
		lesser_moves = calc_moves(*a, *b, lesser);
		while (++i < (*a)->length)
		{
			if (lesser_moves > calc_moves(*a, *b, (*a)->array[i]))
				lesser = (*a)->array[i];
		}
	}
}
