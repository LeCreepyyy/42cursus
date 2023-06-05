/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:23:35 by marvin            #+#    #+#             */
/*   Updated: 2023/06/05 10:45:48 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin_n(char *dst, char *src, int i)
{
	int		j;
	char	*str;

	j = 0;
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
	return (str);
}
