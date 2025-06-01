/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:36:21 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/29 09:26:59 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int calc_moves(t_stack * a, t_stack * b, int number)
{
	int reverse_a;
	int reverse_b;
	int moves_a;
	int moves_b;
	int pos_a;
	int pos_b;
	int amount;

	pos_a = get_pos(a, number, FALSE);
	reverse_a = pos_a > (a->length / 2);
	moves_a = pos_a;
	if (reverse_a)
		moves_a = a->length - pos_a;
	pos_b = get_pos(b, number, TRUE);
	reverse_b = pos_b > (b->length / 2);
	moves_b = pos_b;
	if (reverse_b)
		moves_b = b->length - pos_b;
	amount = 1;
	if (reverse_a == reverse_b)
	{
		if (moves_a > moves_b)
			amount += moves_a;
		amount += moves_b;
	}
	else
		amount += (moves_a + moves_b);
	return (amount);
}