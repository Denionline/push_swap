/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:37:48 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/07 18:28:27 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static char ** fh_getarray(int len, char ** values)
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

void fh_initstack(t_stack ** stack, char * name, size_t size)
{
	(*stack) = malloc(sizeof(t_stack));
	(*stack)->array = malloc(size * sizeof(int));
	(*stack)->length = size;
	(*stack)->name = name;
	if (*name == 'b')
		(*stack)->length = 0;
}

int fh_issrted(t_stack * a, t_stack * b)
{
	if (b->length > 0)
		return (0);
	for (int i = 0; i < a->length; i++)
	{
		for (int j = i; j < a->length; j++)
		{
			if (a->array[i] > a->array[j])
				return (0);
		}
	}
	return (1);
}

int main(int argc, char * argv[])
{
	t_stack * a;
	t_stack * b;
	char **	  values;
	int		  size;
	int		  i;

	if (argc <= 1)
		return (0);
	values = fh_getarray(argc, argv);
	size = 0;
	while (values[size])
		size++;
	fh_initstack(&a, "a", size);
	fh_initstack(&b, "b", size);
	i = 0;
	while (values[i])
	{
		a->array[i] = ft_atoi(values[i]);
		free(values[i++]);
	}
	free(values);
	push_swap(a, b);
	return (0);
}
