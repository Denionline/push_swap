/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:30:56 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/17 23:25:51 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_stack *a, t_stack *b, char **to_clean)
{
	int	i;

	i = 0;
	if (to_clean)
	{
		while (to_clean[i])
			free(to_clean[i++]);
		free(to_clean);
	}
	if (a)
	{
		free(a->array);
		free(a);
	}
	if (b)
	{
		free(b->array);
		free(b);
	}
	ft_putendl_fd("Error", 1);
	exit(1);
}

void	is_exceding_limits(t_stack *a, t_stack *b, long *array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (array[i] > (long)INT_MAX)
			error(a, b, NULL);
		else if ((long)array[i] < (long)INT_MIN)
			error(a, b, NULL);
		i++;
	}
}

void	is_there_duplicate(t_stack *a, t_stack *b, long *array, int length)
{
	int		i;
	int		j;
	long	number;

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

void	check_args(t_stack *a, t_stack *b, char **args)
{
	int	sig;
	int	i;
	int	j;

	i = -1;
	while (args[++i])
	{
		sig = 0;
		j = -1;
		while (args[i][++j])
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
		}
		if (j == sig)
			error(a, b, args);
	}
}
