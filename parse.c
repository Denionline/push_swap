/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:50:14 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/17 23:25:51 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int fh_get_len(char ** args)
{
	int len;

	len = 0;
	while (args[len])
		len++;
	return (len);
}

static void fh_initstack(t_stack ** a, t_stack ** b, int size)
{
	(*a) = malloc(sizeof(t_stack));
	(*b) = malloc(sizeof(t_stack));
	ft_memset(*a, 0, sizeof(**a));
	ft_memset(*b, 0, sizeof(**b));
	if (!(*a) || !(*b))
		return (free((*a)), free((*b)));
	(*a)->array = ft_calloc(size, sizeof(long));
	(*b)->array = ft_calloc(size, sizeof(long));
	if (!(*a)->array || !(*b)->array)
		return (free((*a)->array), free((*b)->array));
	(*a)->name = "a";
	(*b)->name = "b";
	(*a)->len = size;
}

static char ** fh_getarray(char ** values, int len)
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

void parse(t_stack ** a, t_stack ** b, char ** args, int length)
{
	char	**values;
	int		size;
	int		i;

	if (!args[1][0] || length < 2)
		error(NULL, NULL, NULL);
	values = fh_getarray(args, length);
	if (!values)
		return (free(values));
	size = fh_get_len(values);
	fh_initstack(a, b, size);
	check_args(*a, *b, values);
	i = 0;
	while (values[i])
	{
		(*a)->array[i] = ft_atoi(values[i]);
		free(values[i++]);
	}
	free(values);
	is_there_duplicate(*a, *b, (*a)->array, (*a)->len);
	is_exceding_limits(*a, *b, (*a)->array, (*a)->len);
}
