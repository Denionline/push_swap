/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:05:34 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/18 11:24:09 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fh_is_sorted(t_stack *a, t_stack *b)
{
	int	i;

	if (b->len > 0)
		return (FALSE);
	if (a->array[0] != get_smaller(a))
		return (FALSE);
	i = 0;
	while (i < a->len - 1)
	{
		if (a->array[i] > a->array[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static	t_stack	*get_stack(t_stack *a, t_stack *b, char *command)
{
	if (command[1] == 'a' || command[2] == 'a')
		return (a);
	if (command[1] == 'b' || command[2] == 'b')
		return (b);
	return (NULL);
}

static void	commands(t_stack *a, t_stack *b, t_stack *n, char *c)
{
	if (n && c[0] == 's' && c[2] == '\n')
		return (sn(n, FALSE));
	if (n && c[0] == 'r' && c[2] == '\n')
		return (rn(n, FALSE));
	if (n && c[0] == 'r' && c[1] == 'r' && c[3] == '\n')
		return (rrn(n, FALSE));
	if (n && c[0] == 'p' && c[1] == 'a' && c[2] == '\n')
		return (pn(b, a, FALSE));
	if (n && c[0] == 'p' && c[1] == 'b' && c[2] == '\n')
		return (pn(a, b, FALSE));
	if (!n && c[0] == 's' && c[1] == 's' && c[2] == '\n')
		return (ss(a, b, FALSE));
	if (!n && c[0] == 'r' && c[1] == 'r' && c[2] == '\n')
		return (rr(a, b, FALSE));
	if (!n && c[0] == 'r' && c[1] == 'r' && c[2] == 'r' && c[3] == '\n')
		return (rrr(a, b, FALSE));
	free(c);
	error(a, b, NULL);
}

static void	get_commands(t_stack *a, t_stack *b)
{
	char	*command;

	while (TRUE)
	{
		command = get_next_line(0);
		if (!command)
			break ;
		commands(a, b, get_stack(a, b, command), command);
		free(command);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	parse(&a, &b, argv, argc);
	get_commands(a, b);
	if (fh_is_sorted(a, b))
		ft_putendl_fd("\033[0;92mOK\033[0;39m", 1);
	else
		ft_putendl_fd("\033[0;91mKO\033[0;39m", 1);
	free(a->array);
	free(a);
	free(b->array);
	free(b);
	return (0);
}
