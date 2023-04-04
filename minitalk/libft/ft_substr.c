/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:21:57 by vpoirot           #+#    #+#             */
/*   Updated: 2022/11/16 15:59:28 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	char	*strsave;
	size_t	i;

	if (!s)
		return (0);
	if (start >= (unsigned int)ft_strlen(s))
		len = 0;
	i = ft_strlen(s) - start;
	if (i > len)
		i = len;
	newstr = malloc(sizeof(char) * i + 1);
	if (newstr == 0)
		return (0);
	strsave = newstr;
	while (len-- && s[start])
	{
		*newstr = s[start];
		start++;
		newstr++;
	}
	*newstr = '\0';
	return (strsave);
}
