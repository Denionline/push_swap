/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:27:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/22 13:52:17 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	little_sort(t_stack *a)
{
	if (a->len == 2)
	{
		if (a->array[0] > a->array[1])
			sn(a, TRUE);
	}
	else
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
}

static void	fh_push_to_top(t_stack *n, int number)
{
	long	pos_n;
	long	i;

	i = 0;
	pos_n = get_pos(n, number);
	if (pos_n > 0)
	{
		if (pos_n > (n->len / 2))
			while (i++ < (n->len - pos_n))
				rrn(n, TRUE);
		else
			while (i++ < pos_n)
				rn(n, TRUE);
	}
}

static int	fh_is_on_better(long number, t_moves *moves)
{
	long	i;

	i = 0;
	while (i < moves->sequence_len)
	{
		if (moves->sequence[i] == number)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static void	fh_push_no_sequence(t_stack *a, t_stack *b, t_moves *moves)
{
	while (a->len > moves->sequence_len)
	{
		if (fh_is_on_better(a->array[0], moves))
			rn(a, TRUE);
		else
			pn(a, b, TRUE);
	}
}

void	sort(t_stack *a, t_stack *b)
{
	t_moves	actual;
	t_moves	moves;
	long	i;

	if (a->len == 2 || a->len == 3)
		return (little_sort(a));
	ft_find_lis_sequence(a->array, a->len, &moves);
	fh_push_no_sequence(a, b, &moves);
	free(moves.sequence);
	while (b->len > 0)
	{
		moves = calc_moves(a, b, b->array[0]);
		i = 0;
		while (++i < b->len)
		{
			actual = calc_moves(a, b, b->array[i]);
			if (moves.total > actual.total)
				moves = actual;
		}
		if (moves.reverse_a == moves.reverse_b)
			rotate_two(a, b, &moves);
		rotate_one(a, b, &moves);
		pn(b, a, TRUE);
	}
	fh_push_to_top(a, get_smaller(a));
}
