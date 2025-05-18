/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:38:54 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/18 11:49:18 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/include/libft.h"

typedef struct s_node
{
	int				value;
	size_t			index;
	struct s_node	*prev;
	struct s_node	*next;
} t_node;

int	push_swap(char *n);

#endif