/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:27:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/30 10:46:39 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void rotate_one(t_stack * a, t_stack * b, t_moves * moves, int print)
{
	while (moves->pos_a-- > 0)
	{
		if (moves->reverse_a)
			rrn(&a, print);
		else
			rn(&a, print);
	}
	while (moves->pos_b-- > 0)
	{
		if (moves->reverse_b)
			rrn(&b, print);
		else
			rn(&b, print);
	}
}
static void rotate_two(t_stack * a, t_stack * b, t_moves ** moves, int print)
{
	int	amount;
	int i;

	if ((*moves)->pos_a > (*moves)->pos_b)
		amount = (*moves)->pos_b;
	else
		amount = (*moves)->pos_a;
	i = 0;
	while (i < amount)
	{
		if ((*moves)->reverse_a && (*moves)->reverse_b)
			rrr(&a, &b, print);
		else
			rr(&a, &b, print);
		i++;
	}
	(*moves)->pos_a -= amount;
	(*moves)->pos_b -= amount;
}

void push_swap(t_stack * a, t_stack * b, int print)
{
	t_moves * moves;
	t_moves * current;
	int		  i;

	pn(&a, &b, print);
	pn(&a, &b, print);
	while (a->length > 3)
	{
		i = 0;
		moves = calc_moves(a, b, a->array[i]);
		while (i < a->length)
		{
			current = calc_moves(a, b, a->array[i]);
			if ((moves->pos_a + moves->pos_b) > (current->pos_a + current->pos_b))
				moves = current;
			i++;
		}
		if (moves->reverse_a == moves->reverse_b)
			rotate_two(a, b, &moves, print);
		rotate_one(a, b, moves, print);
	}
}
