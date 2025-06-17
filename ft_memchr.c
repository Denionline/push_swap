/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:56:28 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/17 23:25:05 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_s;

	s_s = (unsigned char *)s;
	while (n--)
	{
		if (*s_s == (unsigned char)c)
			return (s_s);
		s_s++;
	}
	return (NULL);
}
