/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:27:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/30 09:57:22 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void push_swap(t_stack * a, t_stack * b, int print)
{
	int current_moves;
	int lesser_moves;
	int lesser;
	int i;

	pn(&a, &b, print);
	pn(&a, &b, print);
	while (a->length > 3)
	{
		i = 0;
		lesser_moves = calc_moves(a, b, a->array[i]);
		while (i < a->length)
		{
			current_moves = calc_moves(a, b, a->array[i]);
			if (lesser_moves > current_moves)
			{
				lesser = a->array[i];
				lesser_moves = current_moves;
			}
			i++;
		}

	}
}
