/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:34:01 by vpoirot           #+#    #+#             */
/*   Updated: 2023/06/13 11:06:22 by vpoirot          ###   ########.fr       */
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

char	*ft_itoa(int nb)
{
	int		len;
	int		div;
	char	*res;

	div = 1;
	len = 0;
	while (nb / div != 0)
	{
		div *= 10;
		len++;
	}
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	div /= 10;
	res[len] = 0;
	while (--len >= 0)
	{
		res[len] = (nb % 10) + 48;
		nb /= 10;
	}
	return (res);
}
