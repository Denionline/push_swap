/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:52:52 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/22 14:22:08 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void ft_rn(t_stack **n)
{
	int	tomove;
	int	i;

	tomove = (*n)->array[0];
	i = -1;
	while (++i < (*n)->length)
		(*n)->array[i] = (*n)->array[i + 1];
	(*n)->array[i - 1] = tomove;
	printf("r%s\n", (*n)->name);
}
