/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:36:21 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/13 15:41:29 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static int get_new_pos(t_stack * b, int number)
{
	int	bigger;
	int	pos;

	bigger = get_bigger(b);
	pos = 0;
	while (pos < b->len)
	{
		if (bigger > b->array[pos] && number < b->array[pos])
			bigger = b->array[pos];
		pos++;
	}
	return (get_pos(b, bigger) + (bigger < number));
}

t_moves calc_moves(t_stack * a, t_stack * b, int number)
{
	t_moves	moves;
	int		moves_a;
	int		moves_b;

	ft_memset(&moves, 0, sizeof(moves));
	moves_a = get_new_pos(a, number);
	moves.reverse_a = moves_a > (a->len / 2);
	moves.a = moves_a;
	if (moves.reverse_a)
		moves.a = a->len - moves_a;
	moves_b = get_pos(b, number);
	moves.reverse_b = moves_b > (b->len / 2);
	moves.b = moves_b;
	if (moves.reverse_b)
		moves.b = b->len - moves_b;
	if (moves.reverse_a == moves.reverse_b && moves.a >= moves.b)
		moves.total = moves.a;
	if (moves.reverse_a == moves.reverse_b && moves.b > moves.a)
		moves.total = moves.b;
	if (moves.reverse_a != moves.reverse_b)
		moves.total = moves.a + moves.b;
	return (moves);
}