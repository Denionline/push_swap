/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:42:43 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/04 15:01:43 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void ss(t_stack * a, t_stack * b, int toprint)
{
	sn(a, FALSE);
	sn(b, FALSE);
	if (toprint)
		ft_putendl_fd("ss", 1);
}
