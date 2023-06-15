/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:54:29 by vpoirot           #+#    #+#             */
/*   Updated: 2023/06/15 14:00:11 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *dst, char *src)
{
	int		j;
	int		i;
	char	*str;

	j = 0;
	i = 0;
	if (!src)
		return (free(dst), NULL);
	if (!dst)
		return (free(src), src);
	str = malloc(((ft_strlen(dst) + ft_strlen(src)) + 1) * sizeof(char));
	if (!str)
		return (free(dst), free(src), NULL);
	if (dst)
	{
		while (dst[i])
		{
			str[i] = dst[i];
			i++;
		}
	}
	while (src[j])
		str[i++] = src[j++];
	str[i] = 0;
	return (free(dst), str);
}
