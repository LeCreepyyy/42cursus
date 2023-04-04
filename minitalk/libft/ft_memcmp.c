/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:27:27 by vpoirot           #+#    #+#             */
/*   Updated: 2022/11/10 15:14:58 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	w;
	char	*a;
	char	*b;

	w = 0;
	a = (char *)s1;
	b = (char *)s2;
	while (w < n)
	{
		if (a[w] != b[w])
			return ((unsigned char)a[w] - (unsigned char)b[w]);
		w++;
	}
	return (0);
}
