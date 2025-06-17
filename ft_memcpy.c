/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:25:43 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/17 23:25:05 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s_src;
	unsigned char	*s_dest;

	s_src = (unsigned char *)src;
	s_dest = (unsigned char *)dest;
	if (!s_dest && !s_src)
		return (dest);
	while (n--)
	{
		*s_dest = *s_src;
		s_dest++;
		s_src++;
	}
	return (dest);
}
