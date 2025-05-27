/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sn.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:42:43 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/26 12:22:49 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	sn(t_stack **n, int toprint)
{
	int	temp;

	temp = (*n)->array[0];
	(*n)->array[0] = (*n)->array[1];
	(*n)->array[1] = temp;
	if (toprint)
		printf("s%s\n", (*n)->name);
}
