/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:36:21 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/12 23:00:13 by dximenes         ###   ########.fr       */
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
	return (get_pos(b, bigger));
}

static void get_min_moves(t_stack * a, t_stack * b, t_moves * moves)
{
	int ra = moves->a;
	int rb = moves->b;
	int rra = a->length - moves->a;
	int rrb = b->length - moves->b;
	int rr = ra > rb ? ra : rb;
	int rrr = rra > rrb ? rra : rrb;
	int	temp_a = ra;
	int	temp_b = rb;


	if (temp_a > (a->length / 2))
	{
		moves->reverse_a = TRUE;
		temp_a = a->length - temp_a;
	}
	if (temp_b > (b->length / 2))
	{
		moves->reverse_b = TRUE;
		temp_b = b->length - temp_b;
	}

	if (moves->reverse_a != moves->reverse_b)
	{
		if ((temp_a + temp_b) <)
	}

	if (rr < rrr)
	{
		moves->reverse_a = FALSE;
		moves->reverse_b = FALSE;
		moves->total = rr;
	}
	else
	{
		moves->a = rra;
		moves->reverse_a = TRUE;
		moves->b = rrb;
		moves->reverse_b = TRUE;
		moves->total = rrr;
	}
}

t_moves calc_moves(t_stack * a, t_stack * b, int number)
{
	t_moves moves;
	// int		max_moves;
	// int		moves_a;
	// int		moves_b;

	ft_memset(&moves, 0, sizeof(moves));

	moves.a = get_pos(a, number);
	moves.b = get_smaller_pos(b, number);

	get_min_moves(a, b, &moves);

	return (moves);
}
