/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:27:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/04 10:49:01 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void rotate_one(t_stack * a, t_stack * b, t_moves * moves, int print)
{
	int i;

	i = 0;
	while (i++ < moves->a)
	{
		if (moves->rr_a)
			rrn(a, print);
		else
			rn(a, print);
	}
	i = 0;
	while (i++ < moves->b)
	{
		if (moves->rr_b)
			rrn(b, print);
		else
			rn(b, print);
	}
}
static void rotate_two(t_stack * a, t_stack * b, t_moves * moves, int print)
{
	int amount;
	int i;

	if (moves->a > moves->b)
		amount = moves->b;
	else
		amount = moves->a;
	i = 0;
	while (i < amount)
	{
		if (moves->rr_a && moves->rr_b)
			rrr(a, b, print);
		else
			rr(a, b, print);
		i++;
	}
	moves->a -= amount;
	moves->b -= amount;
}

static void order_last_three(t_stack * a, int print)
{
	if (a->array[2] < a->array[1] && a->array[2] > a->array[0])
		rrn(a, print);
	else if (a->array[2] < a->array[0] && a->array[2] < a->array[1])
		rrn(a, print);
	else if (a->array[0] > a->array[1] && a->array[0] > a->array[2])
		rn(a, print);
	else if (a->array[0] > a->array[1] && a->array[1] > a->array[2])
		rn(a, print);
	if (a->array[0] > a->array[1] && a->array[2] > a->array[0])
		sn(a, print);
}

static void get_back(t_stack * a, t_stack * b, int print)
{
	int moves_b;
	int i;

	i = 0;
	moves_b = print < 0;
	while (b->length > 0)
	{
		moves_b = get_smaller_pos(a, b->array[0]);
		if (moves_b > (a->length / 2))
			while (i++ < (a->length - moves_b))
				rrn(a, TRUE);
		else
			while (i++ < moves_b)
				rn(a, TRUE);
		pn(b, a, TRUE);
		if (!print)
			fh_print(a, b, a->length > b->length ? a->length : b->length);
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

void push_swap(t_stack * a, t_stack * b, int print)
{
	t_moves moves;
	t_moves current_moves;
	int		smaller;
	int		i;

	ft_memset(&moves, 0, sizeof(moves));
	if (!print)
		fh_print(a, b, a->length > b->length ? a->length : b->length);
	pn(a, b, TRUE);
	pn(a, b, TRUE);
	if (!print)
		fh_print(a, b, a->length > b->length ? a->length : b->length);
	while (a->length > 3)
	{
		i = 0;
		moves = calc_moves(a, b, a->array[i]);
		smaller = a->array[i];
		while (++i < a->length)
		{
			current_moves = calc_moves(a, b, a->array[i]);
			if (moves.total > current_moves.total)
			{
				moves = current_moves;
				smaller = a->array[i];
			}
		}
		if (moves.rr_a == moves.rr_b)
			rotate_two(a, b, &moves, TRUE);
		rotate_one(a, b, &moves, TRUE);
		pn(a, b, TRUE);
		if (!print)
			printf("\n Smaller = %d | Moves a = %d | Moves b = %d | Total = %d\n", smaller, moves.a, moves.b, moves.total);
		if (!print)
			fh_print(a, b, a->length > b->length ? a->length : b->length);
	}
	if (b->array[b->length - 1] > b->array[0])
		rrn(b, TRUE);
	order_last_three(a, print);
	if (!print)
		fh_print(a, b, a->length > b->length ? a->length : b->length);
	put_on_top(b, get_bigger(b));
	if (!print)
		fh_print(a, b, a->length > b->length ? a->length : b->length);
	get_back(a, b, print);
	if (!print)
		fh_print(a, b, a->length > b->length ? a->length : b->length);
	put_on_top(a, get_smaller(a));
	if (!print)
		fh_print(a, b, a->length > b->length ? a->length : b->length);
}
