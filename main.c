/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:37:48 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/18 22:30:08 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*head;
	char	**values;
	int		i;

	i = 0;
	head = NULL;
	values = NULL;
	if (argc <= 1)
		return (0);
	else if (argc == 2)
	{
		values = ft_split(argv[1], ' ');
	}
	else if (argc > 2)
	{
		while(argv[++i])
			values[i - 1] = ft_strdup(argv[i]);
		i = 0;
	}
	while (values[i])
	{
		ft_lstadd_back(&head, ft_lstnew(NULL, ft_atoi(values[i])));
		free(values[i++]);
	}
	free(values);
	ft_lstclear(&head, free);
	return (0);
}
