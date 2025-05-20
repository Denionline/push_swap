/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:37:48 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/20 14:26:47 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static char	**fh_getarray(int len, char **values)
{
	char	**array;
	int		i;

	i = 0;
	if (len == 2)
		return (ft_split(values[1], ' '));
	array = ft_calloc(len + 1, sizeof(char *));
	if (!array)
		return (NULL);
	while(values[++i])
		array[i - 1] = ft_strdup(values[i]);
	array[i] = NULL;
	return (array);
}

static void	fh_newnode(t_node **node, t_node **sup, char **array)
{
	t_list	*lst;
	int		i;

	lst = NULL;
	i = -1;
	while (array[++i])
		ft_lstadd_back(&lst, ft_lstnew(array[i], ft_atoi(array[i])));
	(*node) = malloc(sizeof(t_node));
	(*sup) = malloc(sizeof(t_node));
	if (!(*node) || !(*sup))
		return ;
	(*sup)->name = "b";
	(*node)->name = "a";
	(*node)->top = lst;
	(*node)->bottom = ft_lstlast(lst);
	(*node)->length = ft_lstsize(lst);
	free(array);
}

static void	fh_print(t_node *a, t_node *b)
{
	t_list	*atop;
	t_list	*btop;

	atop = a->top;
	btop = b->top;
	printf("\n");
	while (atop != NULL)
	{
		printf(" %2s", (char *)atop->content);
		printf(" | ");
		if (btop && btop->content != NULL)
			printf("%2s", (char *)btop->content);
		printf("\n");
		atop = atop->next;
		if (btop && btop->content != NULL)
			btop = btop->next;
	}
	printf("----|----\n");
	printf("  a    b\n\n");
}

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;

	if (argc <= 1)
		return (0);
	fh_newnode(&a, &b, fh_getarray(argc, argv));
	push_swap(&a, &b);
	fh_print(a, b);
	ft_lstclear(&a->top, free);
	free(a);
	ft_lstclear(&b->top, free);
	free(b);
	return (0);
}
