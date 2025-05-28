/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:27:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/28 10:58:22 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static int get_pos(t_stack * n, int number, int searchbetween)
{
	int bigger;
	int lesser;
	int pos;
	int i;

	lesser = number;
	i = -1;
	while (searchbetween && ++i < n->length)
		if (n->array[i] < lesser)
			lesser = n->array[i];
	bigger = lesser;
	i = -1;
	while (searchbetween && ++i < n->length)
		if (n->array[i] > bigger)
			bigger = n->array[i];
	if (searchbetween && get_pos(n, bigger, FALSE) > get_pos(n, lesser, FALSE))
		return (get_pos(n, bigger, FALSE) - get_pos(n, lesser, FALSE));
	else if (searchbetween)
		return (get_pos(n, lesser, FALSE) - get_pos(n, bigger, FALSE));
	pos = -1;
	while (++pos < n->length)
		if (n->array[pos] == number)
			break;
	return (pos);
}

static int calc_moves(t_stack * a, t_stack * b, int number)
{
	int moves_a;
	int moves_b;
	int pos_a;
	int pos_b;

	pos_a = get_pos(a, number, FALSE);
	pos_b = get_pos(b, number, TRUE);
	moves_a = pos_a;
	if (pos_a > (a->length / 2))
		moves_a -= a->length;
	moves_b = pos_b;
	if (pos_b > (b->length / 2))
		moves_b -= b->length;
	if ((pos_a > (a->length / 2)) == (pos_b > (b->length / 2)))
	{
		if (moves_a > moves_b)
			return (moves_a - moves_b + 1);
		return (moves_b - moves_a + 1);
	}
	return (moves_a + moves_b + 1);
}

static void rotate(t_stack ** n, int moves, int print)
{
	if (moves > ((*n)->length / 2))
		while ((moves++ - (*n)->length) > 0)
			rrn(n, print);
	else
		while (moves--)
			rn(n, print);
}

static void check_reverse(t_stack ** a, t_stack ** b, int lesser, int moves, int print)
{
	int moves_a;
	int moves_b;

	moves_a = get_pos(*a, lesser, FALSE);
	moves_b = get_pos(*b, lesser, TRUE);
	if ((moves_a > ((*a)->length / 2)) == (moves_b > ((*b)->length / 2)))
	{
		if ((moves_a > ((*a)->length / 2)) && (moves_b > ((*b)->length / 2)))
			while (moves-- > 0)
				rrr(a, b, print);
		else
			while (moves-- > 0)
				rr(a, b, print);
		return;
	}
	rotate(a, moves_a, print);
	rotate(b, moves_b, print);
}

void push_swap(t_stack * a, t_stack * b, int print)
{
	int lesser_moves;
	int lesser;
	int i;

	fh_print(a, b, a->length);
	pn(&a, &b, print);
	pn(&a, &b, print);
	while (a->length > 3)
	{
		i = 0;
		lesser = a->array[i];
		lesser_moves = calc_moves(a, b, lesser);
		while (++i < a->length)
		{
			if (lesser_moves > calc_moves(a, b, a->array[i]))
			{
				lesser = a->array[i];
				lesser_moves = calc_moves(a, b, lesser);
			}
		}
		check_reverse(&a, &b, lesser, lesser_moves, print);
		pn(&a, &b, print);
		fh_print(a, b, a->length > b->length ? a->length : b->length);
	}
}
