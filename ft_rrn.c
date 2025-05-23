/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:44:06 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/23 14:03:43 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_rrn(t_stack **n)
{
	int	tomove;
	int	i;

	tomove = (*n)->array[(*n)->length - 1];
	i = (*n)->length + 1;
	while (--i > 0)
		(*n)->array[i] = (*n)->array[i - 1];
	(*n)->array[0] = tomove;
	printf("rr%s\n", (*n)->name);
}