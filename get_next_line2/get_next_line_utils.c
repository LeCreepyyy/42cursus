/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:55:05 by vpoirot           #+#    #+#             */
/*   Updated: 2023/03/21 10:27:17 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	len_str(const char *str)
{
	size_t	a;

	a = 0;
	if (!str)
		return (0);
	while (str[a] != '\0')
		a++;
	return (a);
}

void	ft_bzero(void *w, size_t n)
{
	char	*e;
	size_t	i;

	e = w;
	i = 0;
	while (i < n)
	{
		e[i] = 0;
		i++;
	}
	w = e;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*table;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	table = malloc(nmemb * size);
	if (!table)
		return (0);
	ft_bzero(table, nmemb * size);
	return (table);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	lenstock;

	i = -1;
	j = -1;
	lenstock = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1[0] != '\0')
		lenstock = len_str(s1);
	str = calloc(lenstock + len_str(s2) + 1, sizeof(char));
	if (s1)
	{
		while (s1[++i] != '\0')
			str[i] = s1[i];
	}
	if (s2)
	{
		while (s2[++j] != '\0')
			str[i + j] = s2[j];
	}
	str[i + j] = '\0';
	free ((char *)s1);
	return (str);
}
