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

// #include "include/push_swap.h"

// static int get_next(int * array, int len, int number)
// {
// 	int i;
// 	int actual;

// 	actual = number;
// 	i = 0;
// 	while (i < len)
// 	{
// 		if (array[i] > actual)
// 			actual = array[i];
// 		i++;
// 	}
// 	i = 0;
// 	while (i < len)
// 	{
// 		if (array[i] < actual && array[i] > number)
// 			actual = array[i];
// 		i++;
// 	}
// 	return (actual);
// }

// static void get_better(int * array, t_moves * moves)
// {
// 	int j;
// 	int i;

// 	j = 0;
// 	i = 0;
// 	moves->better[j] = array[i];
// 	while (i < moves->better_len)
// 	{
// 		if (array[i] < get_next(array + i, moves->better_len, array[i]))
// 			moves->better[++j] = get_next(array + i, moves->better_len, array[i]);
// 		i++;
// 	}
// }

// static int get_possibilities(int * array, int len)
// {
// 	int amount;
// 	int i;

// 	amount = 0;
// 	i = 0;
// 	while (i < len)
// 	{
// 		if (array[i] != get_next(array + i, len, array[i]))
// 			amount++;
// 		i++;
// 	}
// 	return (amount);
// }

// void better_array(t_stack * a, t_moves * moves)
// {
// 	int best_possibilities;
// 	int possibilities;
// 	int position;
// 	int i;

// 	moves->better = malloc((a->length / 2) * sizeof(int));
// 	if (!moves->better)
// 		return;
// 	best_possibilities = 0;
// 	position = 0;
// 	i = 0;
// 	while (i < a->length)
// 	{
// 		possibilities = get_possibilities(a->array + i, a->length);
// 		if (possibilities > best_possibilities)
// 		{
// 			best_possibilities = possibilities;
// 			position = i;
// 		}
// 		i++;
// 	}
// 	moves->better_len = best_possibilities;
// 	get_better(a->array + position, moves);
// }
