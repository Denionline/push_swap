/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:36:21 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/13 12:00:41 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int get_pos(t_stack * n, int number)
{
	int pos;

	pos = 0;
	while (pos < n->length)
	{
		if (n->array[pos] == number)
			return (pos);
		pos++;
	}
	return (-1);
}

int get_bigger(t_stack * n)
{
	int bigger;
	int pos;

	bigger = n->array[0];
	pos = 0;
	while (pos < n->length)
	{
		if (n->array[pos] > bigger)
			bigger = n->array[pos];
		pos++;
	}
	return (bigger);
}
int get_smaller(t_stack * n)
{
	int smaller;
	int pos;

	smaller = n->array[0];
	pos = 0;
	while (pos < n->length)
	{
		if (n->array[pos] < smaller)
			smaller = n->array[pos];
		pos++;
	}
	return (smaller);
}

int get_smaller_pos(t_stack * b, int number)
{
	int smaller;
	int pos;

	smaller = get_smaller(b);
	pos = 0;
	while (pos < b->length)
	{
		if (smaller < b->array[pos] && number > b->array[pos])
			smaller = b->array[pos];
		pos++;
	}
	return (get_pos(b, smaller));
}

int get_bigger_pos(t_stack * b, int number)
{
	int bigger;
	int pos;

	bigger = get_bigger(b);
	pos = 0;
	while (pos < b->length)
	{
		if (bigger > b->array[pos] && number < b->array[pos])
			bigger = b->array[pos];
		pos++;
	}
	pos = get_pos(b, bigger);
	if (bigger < number)
		pos++;
	return (pos);
}

t_moves calc_moves(t_stack * a, t_stack * b, int number)
{
	t_moves moves;
	int		moves_a;
	int		moves_b;

	ft_memset(&moves, 0, sizeof(moves));
	moves_a = get_pos(a, number);
	moves.reverse_a = moves_a > (a->length / 2);
	moves.a = moves_a;
	if (moves.reverse_a)
		moves.a = a->length - moves_a;
	moves_b = get_bigger_pos(b, number);
	moves.reverse_b = moves_b > (b->length / 2);
	moves.b = moves_b;
	if (moves.reverse_b)
		moves.b = b->length - moves_b;
	if (moves.reverse_a == moves.reverse_b && moves.a >= moves.b)
		moves.total = moves.a;
	if (moves.reverse_a == moves.reverse_b && moves.b > moves.a)
		moves.total = moves.b;
	if (moves.reverse_a != moves.reverse_b)
		moves.total = moves.a + moves.b;
	return (moves);
}