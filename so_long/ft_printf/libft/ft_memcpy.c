/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:03:47 by vpoirot           #+#    #+#             */
/*   Updated: 2022/11/22 15:17:03 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*e;
	const unsigned char	*q;
	size_t				i;

	i = 0;
	e = dst;
	q = src;
	if ((e == 0 && q == 0) && n >= 0)
		return (e);
	while (n > 0)
	{
		e[i] = q[i];
		i++;
		n--;
	}
	dst = e;
	return (dst);
}
