/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:34:01 by vpoirot           #+#    #+#             */
/*   Updated: 2023/06/06 13:52:10 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		mult;
	int		nb;

	mult = 1;
	nb = 0;
	i = 0;
	if (nptr[i] == '-' && nptr[i + 1] >= '0' && nptr[i + 1] <= '9')
		mult = -1;
	if (!(nptr[i] == '+' || nptr[i] == '-'))
		if (!(nptr[i] >= '0' && nptr[i] <= '9'))
			return (0);
	if (nptr[i] >= '0' && nptr[i] <= '9')
		i--;
	i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		nb = (nb * 10) + (nptr[i++] - '0');
	nb *= mult;
	return (nb);
}

char	*ft_strjoin(char *dst, char *src, int i)
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
	return (free(dst), str);
}
