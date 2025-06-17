/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:44:06 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/17 20:29:40 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void rrr(t_stack * a, t_stack * b, int toprint)
{
	rrn(a, FALSE);
	rrn(b, FALSE);
	if (toprint)
		ft_putendl_fd("rrr", 1);
}