/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:50:40 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/09 19:16:43 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static int * get_better(int * array, int * better, int len)
{
	int j;
	int i;

	j = 0;
	i = 0;
	while (i < len)
	{
		if (array[i] < array[i + 1])
			better[j++] = array[i];
		i++;
	}
	return (better);
}

static int get_possibilities(int * array, int len)
{
	int amount;
	int i;

	amount = 0;
	i = 0;
	while (i < len)
	{
		if (array[i] < array[i + 1])
			amount++;
		i++;
	}
	return (amount);
}

int * better_array(t_stack * a, t_moves * moves)
{
	int * new_better;
	int	  best_possibilities;
	int	  possibilities;
	int	  position;
	int	  i;

	new_better = malloc((a->length / 2) * sizeof(int));
	if (!new_better)
		return (NULL);
	best_possibilities = a->length;
	position = 0;
	i = 0;
	while (i < a->length)
	{
		possibilities = get_possibilities(a->array + i, a->length);
		if (possibilities < best_possibilities)
		{
			best_possibilities = possibilities;
			position = i;
		}
		i++;
	}
	moves->better_len = best_possibilities;
	return (get_better(a->array + position, new_better, moves->better_len));
}
