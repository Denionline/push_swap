/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:27:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/13 11:44:47 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// static void order_last_three(t_stack * a)
// {
// 	if (a->array[0] > a->array[1] && a->array[1] > a->array[2])
// 		rn(a, TRUE);
// 	else if (a->array[2] < a->array[1] && a->array[2] > a->array[0])
// 		rrn(a, TRUE);
// 	else if (a->array[0] > a->array[1] && a->array[0] > a->array[2])
// 		rn(a, TRUE);
// 	else if (a->array[2] < a->array[0] && a->array[2] < a->array[1])
// 		rrn(a, TRUE);
// 	if (a->array[0] > a->array[1])
// 		sn(a, TRUE);
// }

// static void get_back(t_stack * a, t_stack * b)
// {
// 	int moves_b;
// 	int i;

// 	moves_b = 0;
// 	while (b->length > 0)
// 	{
// 		i = 0;
// 		moves_b = get_bigger_pos(a, b->array[0]);
// 		if (moves_b > (a->length / 2))
// 			while (i++ < (a->length - moves_b))
// 				rrn(a, TRUE);
// 		else
// 			while (i++ < moves_b)
// 				rn(a, TRUE);
// 		pn(b, a);
// 		if (a->array[0] > a->array[1])
// 			sn(a, TRUE);
// 	}
// }

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

static int is_on_better(int number, t_moves * moves)
{
	int i;

	i = 0;
	while (i < moves->better_len)
	{
		if (moves->better[i] == number)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int * ft_find_lis(int * array, int len, int * lis_len)
{
	int * dp = malloc(len * sizeof(int));
	int * prev = malloc(len * sizeof(int));
	int	  max = 0, max_idx = 0;
	int * lis;
	int	  i, j, k;

	for (i = 0; i < len; i++)
	{
		dp[i] = 1;
		prev[i] = -1;
		for (j = 0; j < i; j++)
		{
			if (array[j] < array[i] && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				prev[i] = j;
			}
		}
		if (dp[i] > max)
		{
			max = dp[i];
			max_idx = i;
		}
	}
	*lis_len = max;
	lis = malloc(max * sizeof(int));
	k = max - 1;
	while (max_idx >= 0)
	{
		lis[k--] = array[max_idx];
		max_idx = prev[max_idx];
	}
	free(dp);
	free(prev);
	return lis;
}

void push_swap(t_stack * a, t_stack * b)
{
	t_moves current_moves;
	t_moves moves;
	int		i;

	moves.better = ft_find_lis(a->array, a->length, &moves.better_len);
	while (a->length > moves.better_len)
	{
		if (is_on_better(a->array[0], &moves))
			rn(a, TRUE);
		else
			pn(a, b);
	}
	while (b->length > 0)
	{
		moves = calc_moves(b, a, b->array[0]);
		i = 0;
		while (++i < b->length)
		{
			current_moves = calc_moves(b, a, b->array[i]);
			if (moves.total > current_moves.total)
				moves = current_moves;
		}
		if (moves.reverse_a == moves.reverse_b)
			rotate_two(b, a, &moves);
		rotate_one(b, a, &moves);
		pn(b, a);
	}
	// order_last_three(a);
	// get_back(a, b);
	put_on_top(a, get_smaller(a));
}
