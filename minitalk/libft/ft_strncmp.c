/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:21:54 by vpoirot           #+#    #+#             */
/*   Updated: 2022/11/10 15:36:07 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == 0)
			return (0);
		i++;
	}
	return (0);
}
/*
int main()
{
	char	s1[] = "atoms\0\0\0\0";
	char	s2[] = "atoms\0abc";

	printf("%d\n", strncmp(s1, s2, 6));
	printf("%d\n", ft_strncmp("atoms\0\0\0\0", "atoms\0abc", 6));
}*/
