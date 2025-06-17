/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:17:27 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/17 23:25:51 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rr(t_stack * a, t_stack * b, int toprint)
{
	rn(a, FALSE);
	rn(b, FALSE);
	if (toprint)
		ft_putendl_fd("rr", 1);
}
