/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:27:10 by dximenes          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/06/01 23:43:58 by dximenes         ###   ########.fr       */
=======
/*   Updated: 2025/06/07 17:40:17 by dximenes         ###   ########.fr       */
>>>>>>> cheap
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

<<<<<<< HEAD
	bigger = a->array[0];
	i = 0;
	while (i < a->length)
	{
		if (a->array[i] > bigger)
			bigger = a->array[i];
		i++;
	}
	lesser = bigger;
	i = 0;
	while (i < a->length)
	{
		if (a->array[i] < lesser && a->array[i] > number)
			lesser = a->array[i];
		i++;
	}
	pos = -1;
	while (++pos < a->length)
		if (a->array[pos] == lesser)
			break;
	if (bigger < number)
		pos++;
	return (pos);
}

static void put_back_to_stack_a(t_stack * a, t_stack * b, int print)
{
	int pos_a;
	int moves;
	int moves_amount;

=======
	moves_b = 0;
>>>>>>> cheap
	while (b->length > 0)
	{
		i = 0;
		moves_b = get_bigger_pos(a, b->array[0]);
		if (moves_b > (a->length / 2))
			while (i++ < (a->length - moves_b))
				rrn(a, TRUE);
		else
<<<<<<< HEAD
			rotate_one(a, pos_a, FALSE, print);
		pn(b, a, print);
		// fh_print(a, b, a->length > b->length ? a->length : b->length);
=======
			while (i++ < moves_b)
				rn(a, TRUE);
		pn(b, a);
		if (a->array[0] > a->array[1])
			sn(a, TRUE);
>>>>>>> cheap
	}
}

static void put_on_top(t_stack * n, int number)
{
	int pos_n;
	int i;

<<<<<<< HEAD
	// fh_print(a, b, a->length);
	pn(a, b, print);
	pn(a, b, print);
=======
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

void push_swap(t_stack * a, t_stack * b)
{
	t_moves moves;
	t_moves current_moves;
	int		i;

	pn(a, b);
	pn(a, b);
>>>>>>> cheap
	while (a->length > 3)
	{
		i = 0;
		moves = calc_moves(a, b, a->array[i]);
		while (++i < a->length)
		{
			current_moves = calc_moves(a, b, a->array[i]);
			if (moves.total > current_moves.total)
				moves = current_moves;
		}
<<<<<<< HEAD
		// printf("lesser => %d\n", lesser);
		check_rotate(a, b, lesser, print);
		pn(a, b, print);
		// fh_print(a, b, a->length > b->length ? a->length : b->length);
	}
	if (b->array[0] < b->array[b->length - 1])
		rn(&b, print);
	order_last_three(a, print);
	// fh_print(a, b, a->length > b->length ? a->length : b->length);
	// printf("-------------Pushing back to stack a-----------------\n");
	put_back_to_stack_a(a, b, print);
	// fh_print(a, b, a->length > b->length ? a->length : b->length);
	i = 0;
	lesser = a->array[0];
	lesser_moves = 0;
	while (i < a->length)
	{
		if (a->array[i] < lesser)
		{
			lesser = a->array[i];
			lesser_moves = i;
		}
		i++;
	}
	// printf("lesser pos => %d\n", lesser_moves);
	if (lesser_moves > (a->length / 2))
	{
		lesser_moves = a->length - lesser_moves;
		
		i = 0;
		while (i < lesser_moves)
		{
			rrn(&a, print);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < lesser_moves)
		{
			rn(&a, print);
			i++;
		}
	}
	// fh_print(a, b, a->length > b->length ? a->length : b->length);
=======
		if (moves.reverse_a == moves.reverse_b)
			rotate_two(a, b, &moves);
		rotate_one(a, b, &moves);
		pn(a, b);
	}
	order_last_three(a);
	get_back(a, b);
	put_on_top(a, get_smaller(a));
>>>>>>> cheap
}
