/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:27:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/13 15:18:57 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void put_on_top(t_stack * n, int number)
{
	int pos_n;
	int i;

	i = 0;
	pos_n = get_pos(n, number);
	if (pos_n > 0)
	{
		if (pos_n > (n->len / 2))
			while (i++ < (n->len - pos_n))
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
	while (i < moves->best_seq_len)
	{
		if (moves->best_seq[i] == number)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void push_swap(t_stack * a, t_stack * b)
{
	t_moves current_moves;
	t_moves moves;
	int		i;

	moves.best_seq = find_lis_sequence(a->array, a->len, &moves.best_seq_len);
	while (a->len > moves.best_seq_len)
	{
		if (is_on_better(a->array[0], &moves))
			rn(a, TRUE);
		else
			pn(a, b);
	}
	while (b->len > 0)
	{
		moves = calc_moves(b, a, b->array[0]);
		i = 0;
		while (++i < b->len)
		{
			current_moves = calc_moves(b, a, b->array[i]);
			if (moves.total > current_moves.total)
				moves = current_moves;
		}
		if (moves.reverse_a == moves.reverse_b)
			rotate_two(b, a, &moves);
		rotate_one(b, a, &moves);
		pn(b, a);
	}
	put_on_top(a, get_smaller(a));
}
