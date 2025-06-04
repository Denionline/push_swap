/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:20:05 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/04 17:21:07 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void rotate_one(t_stack * a, t_stack * b, t_moves * moves)
{
	int i;

	i = 0;
	while (i++ < moves->a)
	{
		if (moves->rr_a)
			rrn(a, TRUE);
		else
			rn(a, TRUE);
	}
	i = 0;
	while (i++ < moves->b)
	{
		if (moves->rr_b)
			rrn(b, TRUE);
		else
			rn(b, TRUE);
	}
}
void rotate_two(t_stack * a, t_stack * b, t_moves * moves)
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
			rrr(a, b);
		else
			rr(a, b);
		i++;
	}
	moves->a -= amount;
	moves->b -= amount;
}