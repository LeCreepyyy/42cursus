/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:23 by vpoirot           #+#    #+#             */
/*   Updated: 2023/04/06 12:30:24 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			w;
	unsigned char	*q;

	w = 0;
	q = (unsigned char *)s;
	while (w < n)
	{
		if (q[w] == (unsigned char)c)
			return ((void *)(s + w));
		w++;
	}
	return (0);
}
