// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   better_array.c                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/06/09 18:50:40 by dximenes          #+#    #+#             */
// /*   Updated: 2025/06/11 11:18:52 by dximenes         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "include/push_swap.h"

static int get_next(int * array, int len, int number)
{
	int bigger;
	int actual;
	int i;

	bigger = number;
	i = 0;
	while (i < len)
	{
		if (array[i] > bigger)
			bigger = array[i];
		i++;
	}
	actual = bigger;
	i = 0;
	while (i < len)
	{
		if (array[i] < actual && array[i] > number)
			actual = array[i];
		i++;
	}
	if (actual == bigger)
		return (number);
	return (actual);
}

static int get_idx(int * array, int number)
{
	int i;

	i = 0;
	while (array[i] != number)
		i++;
	return (i);
}

static void get_better(int * array, int len, t_moves * moves)
{
	int current;
	int i;
	int j;

	j = 0;
	i = 0;
	current = array[i];
	while (current != get_next(array + i, len - i, current))
	{
		current = get_next(array + i, len - i, current);
		i += get_idx(array, current);
		moves->better[j++] = current;
	}
}

static int get_possibilities(int * array, int len)
{
	int current;
	int amount;
	int i;

	amount = 0;
	i = 0;
	current = array[i];
	while (current != get_next(array + i, len - i, current))
	{
		current = get_next(array + i, len - i, current);
		i += get_idx(array, current);
		amount++;
	}
	return (amount);
}

void better_array(t_stack * a, t_moves * moves)
{
	int best_possibilities;
	int possibilities;
	int position;
	int i;

	moves->better = malloc((a->length / 2) * sizeof(int));
	if (!moves->better)
		return;
	best_possibilities = 0;
	position = 0;
	i = 0;
	while (i < a->length)
	{
		possibilities = get_possibilities(a->array + i, a->length);
		if (possibilities > best_possibilities)
		{
			best_possibilities = possibilities;
			position = i;
		}
		i++;
	}
	moves->better_len = best_possibilities;
	get_better(a->array + position, a->length, moves);
}
