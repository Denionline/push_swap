/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lis_sequence.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:28:20 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/13 18:35:29 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void	fh_get_sequence(int *array, int *b_p, int *b_idx, int pos)
{
	int	j;

	j = 0;
	while (j < pos)
	{
		if (array[j] < array[pos] && b_p[j] + 1 > b_p[pos])
		{
			b_p[pos] = b_p[j] + 1;
			b_idx[pos] = j;
		}
		j++;
	}
}

static int	*fh_get_lis(int * arr, int * b_p, int * b_idx, int max, int idx)
{
	int	*lis;
	int	k;

	lis = malloc(max * sizeof(int));
	k = max - 1;
	while (idx >= 0)
	{
		lis[k--] = arr[idx];
		idx = b_idx[idx];
	}
	return (free(b_idx), free(b_p), lis);
}

static int	fh_get_best_idx(int * arr, int * b_p, int * b_idx, int * mx, int ln)
{
	int	mx_idx;
	int	i;

	mx_idx = 0;
	i = 0;
	while (i < ln)
	{
		b_p[i] = 1;
		b_idx[i] = -1;
		fh_get_sequence(arr, b_p, b_idx, i);
		if (b_p[i] > *mx)
		{
			*mx = b_p[i];
			mx_idx = i;
		}
		i++;
	}
	return (mx_idx);
}

void	ft_find_lis_sequence(int * array, int len, t_moves *moves)
{
	int	*best_poss;
	int	*best_idx;
	int	max;
	int	max_idx;

	max = 0;
	best_poss = malloc(len * sizeof(int));
	best_idx = malloc(len * sizeof(int));
	if (!best_poss || !best_poss)
		return (free(best_poss), free(best_idx));
	max_idx = fh_get_best_idx(array, best_poss, best_idx, &max, len);
	moves->sequence_len = max;
	moves->sequence = fh_get_lis(array, best_poss, best_idx, max, max_idx);
}
