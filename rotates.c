/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:20:05 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/18 00:38:25 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_one(t_stack *a, t_stack *b, t_moves *moves)
{
	int	i;

	i = 0;
	while (i < moves->a)
	{
		if (moves->reverse_a)
			rrn(a, TRUE);
		else
			rn(a, TRUE);
		i++;
	}
	i = 0;
	while (i < moves->b)
	{
		if (moves->reverse_b)
			rrn(b, TRUE);
		else
			rn(b, TRUE);
		i++;
	}
}

void	rotate_two(t_stack *a, t_stack *b, t_moves *moves)
{
	int	amount;
	int	i;

	if (moves->a > moves->b)
		amount = moves->b;
	else
		amount = moves->a;
	i = 0;
	while (i < amount)
	{
		if (moves->reverse_a && moves->reverse_b)
			rrr(a, b, TRUE);
		else
			rr(a, b, TRUE);
		i++;
	}
	moves->a -= amount;
	moves->b -= amount;
}
