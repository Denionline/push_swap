/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:27:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/06 12:39:49 by dximenes         ###   ########.fr       */
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

	moves_b = 0;
	while (b->length > 0)
	{
		i = 0;
		moves_b = get_bigger_pos(a, b->array[0]);
		if (moves_b > (a->length / 2))
			while (i++ < (a->length - moves_b))
				rrn(a, TRUE);
		else
			while (i++ < moves_b)
				rn(a, TRUE);
		pn(b, a);
		if (a->array[0] > a->array[1])
			sn(a, TRUE);
	}
}

static void put_on_top(t_stack * n, int number)
{
	int pos_n;
	int i;

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
    int chunk_count = 5; // ou 10, teste o que for melhor
    int chunk_size = a->length / chunk_count;
    int *sorted = get_sorted_array(a); // você precisa implementar isso
    int chunk_min, chunk_max, i, j;

    for (i = 0; i < chunk_count; i++)
    {
        chunk_min = sorted[i * chunk_size];
        chunk_max = sorted[(i + 1) * chunk_size - 1];
        j = 0;
        while (j < a->length)
        {
            if (a->array[0] >= chunk_min && a->array[0] <= chunk_max)
                pn(a, b);
            else
                rn(a, TRUE);
            j++;
        }
    }
    // Depois, traga de volta de B para A como já faz em get_back
    order_last_three(a);
    get_back(a, b);
    put_on_top(a, get_smaller(a));
}
