/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:27:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/09 19:32:19 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

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

static int is_on_better(int number, t_moves * moves)
{
	int i;

	i = 0;
	while (i < moves->better_len)
	{
		if (moves->better[i] == number)
			return (1);
		i++;
	}
	return (0);
}

void push_swap(t_stack * a, t_stack * b)
{
	t_moves current_moves;
	t_moves moves;
	int		i;

	pn(a, b);
	pn(a, b);
	moves.better = better_array(a, &moves);
	while (a->length > 3)
	{
		i = 0;
		moves = calc_moves(a, b, a->array[i]);
		while (!is_on_better(a->array[i++], &moves) && i < a->length)
		{
			current_moves = calc_moves(a, b, a->array[i]);
			if (moves.total > current_moves.total)
				moves = current_moves;
		}
		if (is_on_better(a->array[i++], &moves))
			rn(a, TRUE);
		else
		{
			if (moves.reverse_a == moves.reverse_b)
				rotate_two(a, b, &moves);
			rotate_one(a, b, &moves);
			pn(a, b);
		}
	}
	order_last_three(a);
	get_back(a, b);
	put_on_top(a, get_smaller(a));
}
