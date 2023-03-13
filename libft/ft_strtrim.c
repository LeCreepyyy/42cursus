/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:12:52 by vpoirot           #+#    #+#             */
/*   Updated: 2022/11/29 11:44:05 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_setchr(char const *s, char const *set)
{
	int	l;
	int	c;

	l = 0;
	c = 0;
	while (s[l] && ft_strchr(set, s[l]))
	{
		c++;
		l++;
	}
	return (c);
}

size_t	ft_setbchr(char const *s, char const *set)
{
	int	l;
	int	c;

	l = ft_strlen(s) - 1;
	c = 0;
	while (l > 0 && ft_strchr(set, s[l]))
	{
		if ((size_t)l == ft_setchr(s, set) - 1)
			break ;
		c++;
		l--;
	}
	return (c);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char	*str;
	char	*strsave;
	size_t	lset;

	if (!s || !set)
		return (0);
	str = malloc(ft_strlen(s) - (ft_setchr(s, set) + ft_setbchr(s, set)) + 1);
	if (str == 0)
		return (0);
	lset = ft_setchr(s, set);
	strsave = str;
	while (s[lset])
	{
		if (lset == ft_strlen(s) - ft_setbchr(s, set))
			break ;
		*str = s[lset];
		str++;
		lset++;
	}
	*str = 0;
	return (strsave);
}
