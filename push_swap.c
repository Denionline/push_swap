/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:37:48 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/17 23:25:51 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char * argv[])
{
	t_stack * a;
	t_stack * b;

	parse(&a, &b, argv, argc);
	sort(a, b);
	return (free(a->array), free(a), free(b->array), free(b), 0);
}
