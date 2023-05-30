/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:23:35 by marvin            #+#    #+#             */
/*   Updated: 2023/05/30 09:56:25 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *dst, char *src)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!src)
		return (NULL);
	if (!dst)
		return (src);
	str = malloc(((ft_strlen(dst) + ft_strlen(src)) + 1) * sizeof(char));
	if (!str)
		return (NULL);
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
