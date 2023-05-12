/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:54:29 by vpoirot           #+#    #+#             */
/*   Updated: 2023/05/12 14:34:55 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char *s2)
{
	char	*str;
	char	*strsave;
	char	*s2save;

	if (s1 == 0 || s2 == 0)
		return (0);
	s2save = s2;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	strsave = str;
	if (!str)
		return (0);
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str++ = 0;
	free(s2save);
	return (strsave);
}
