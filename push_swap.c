/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:37:48 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/13 18:31:40 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc <= 1)
		return (0);
	ft_memset(&a, 0, sizeof(a));
	ft_memset(&b, 0, sizeof(b));
	parse(&a, &b, argv, argc);
	sort(a, b);
	free(a->array);
	free(a);
	free(b->array);
	free(b);
	return (0);
}
