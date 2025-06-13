/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:50:14 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/13 18:22:32 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void fh_initstack(t_stack **a, t_stack **b, int size)
{
	(*a) = malloc(sizeof(t_stack));
	(*b) = malloc(sizeof(t_stack));
	if (!(*a) || !(*b))
		return (free((*a)), free((*b)));
	(*a)->array = malloc(size * sizeof(int));
	(*b)->array = malloc(size * sizeof(int));
	if (!(*a)->array || !(*b)->array)
		return (free((*a)->array), free((*b)->array));
	(*a)->name = "a";
	(*b)->name = "b";
	(*a)->len = size;
}

static char **fh_getarray(char ** values, int len)
{
	char ** array;
	int		i;

	i = 0;
	if (len == 2)
		return (ft_split(values[1], ' '));
	array = ft_calloc(len + 1, sizeof(char *));
	if (!array)
		return (NULL);
	while (values[++i])
		array[i - 1] = ft_strdup(values[i]);
	array[i] = NULL;
	return (array);
}

void	parse(t_stack **a, t_stack **b, char **args, int length)
{
	char	**values;
	int		size;
	int		i;

	values = fh_getarray(args, length);
	if (!values)
		return (free(values));
	size = 0;
	while (values[size])
		size++;
	fh_initstack(a, b, size);
	i = 0;
	while (values[i])
	{
		(*a)->array[i] = ft_atoi(values[i]);
		free(values[i++]);
	}
	free(values);
}