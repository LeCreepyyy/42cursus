/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:43:18 by vpoirot           #+#    #+#             */
/*   Updated: 2023/04/06 12:30:43 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		a;
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (d == 0 && s == 0)
		return (d);
	if (d < s)
	{
		a = 0;
		while (a < len)
		{
			d[a] = s[a];
			a++;
		}
	}
	else
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	return (d);
}
