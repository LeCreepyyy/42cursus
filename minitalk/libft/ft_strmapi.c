/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:01:51 by vpoirot           #+#    #+#             */
/*   Updated: 2022/12/05 15:05:34 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;
	char	*savestr;

	i = -1;
	if (s == 0)
		return (0);
	str = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (str == 0)
		return (0);
	savestr = str;
	while (s[++i])
	{
		*str = f(i, s[i]);
		str++;
	}
	*str = 0;
	return (savestr);
}
