/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:55:05 by vpoirot           #+#    #+#             */
/*   Updated: 2023/03/15 13:53:13 by vpoirot          ###   ########.fr       */
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

int	size_count(const char *stock)
{
	size_t	i;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	return (i);
}

char	*gnl_eof(char *stock)
{
	static int	finish;

	if (!finish)
		finish = 0;
	if (finish == 1 || stock[0] == '\0')
	{
		free (stock);
		stock = 0;
		return (0);
	}
	finish = 1;
	return (stock);
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
	str = malloc(sizeof(char) * (lenstock + len_str(s2) + 1));
	if (!str)
		return (NULL);
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
	return (str);
}
