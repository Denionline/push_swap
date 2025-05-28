/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:27:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/28 17:57:32 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static int rotate_two(t_stack ** a, t_stack ** b, int moves, int reverse, int print)
{
	int moves_amount;

	moves_amount = 0;
	while (moves_amount++ < moves)
	{
		if (reverse)
			rrr(a, b, print);
		else
			rr(a, b, print);
	}
	return (moves_amount);
}

static void rotate_one(t_stack ** n, int moves, int reverse, int print)
{
	int moves_amount;

	moves_amount = 0;
	while (moves_amount++ < moves)
	{
		if (reverse)
			rrn(n, print);
		else
			rn(n, print);
	}
}

static void check_rotate(t_stack ** a, t_stack ** b, int lesser, int print)
{
	int	reverse_a;
	int	reverse_b;
	int moves_a;
	int moves_b;
	int pos_a;
	int pos_b;
	int amount;

	pos_a = get_pos(*a, lesser, FALSE);
	reverse_a = pos_a > ((*a)->length / 2);
	moves_a = pos_a;
	if (reverse_a)
		moves_a = (*a)->length - ++pos_a;
	pos_b = get_pos(*b, lesser, TRUE);
	reverse_b = pos_b > ((*b)->length / 2);
	moves_b = pos_b;
	if (reverse_b)
		moves_b = (*b)->length - ++pos_b;
	if ((pos_a && pos_b) && (reverse_a == reverse_b))
	{
		if (moves_a > moves_b)
			amount = rotate_two(a, b, (moves_a - moves_b), reverse_a, print);
		else
			amount = rotate_two(a, b, (moves_b - moves_a), reverse_a, print);
		moves_a -= amount;
		moves_b -= amount;
	}
	rotate_one(a, moves_a, reverse_a, print);
	rotate_one(b, moves_b, reverse_b, print);
}

void push_swap(t_stack * a, t_stack * b, int print)
{
	int lesser_moves;
	int current;
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
			current = calc_moves(a, b, a->array[i]);
			if (lesser_moves > current)
			{
				lesser = a->array[i];
				lesser_moves = current;
			}
		}
		printf("lesser => %d\n", lesser);
		check_rotate(&a, &b, lesser, print);
		pn(&a, &b, print);
		fh_print(a, b, a->length > b->length ? a->length : b->length);
	}
}
