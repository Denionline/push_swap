/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:30:56 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/13 23:17:55 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void error(t_stack * a, t_stack * b, char ** to_clean)
{
	int i;

	i = 0;
	while (to_clean && to_clean[i])
		free(to_clean[i++]);
	free(to_clean);
	free(a->array);
	free(a);
	free(b->array);
	free(b);
	ft_putendl_fd("Error", 1);
	exit(1);
}

void is_there_duplicate(t_stack * a, t_stack * b, size_t * array, int length)
{
	int i;
	int j;
	size_t number;

	i = 0;
	while (i < length)
	{
		j = i;
		number = array[i];
		while (++j < length)
			if (number == array[j])
				error(a, b, NULL);
		i++;
	}
}

void check_args(t_stack * a, t_stack * b, char ** args)
{
	int sig;
	int i;
	int j;

	i = 0;
	while (args[i])
	{
		sig = 0;
		j = 0;
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
			{
				if (args[i][j] == '-' || args[i][j] == '+')
					sig++;
				else
					error(a, b, args);
				if (sig > 1)
					error(a, b, args);
			}
			j++;
		}
		i++;
	}
}
