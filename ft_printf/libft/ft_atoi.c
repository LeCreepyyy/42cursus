/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:55:06 by vpoirot           #+#    #+#             */
/*   Updated: 2022/12/01 12:52:00 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	wspace(const char t)
{
	return (t == '\t' || t == '\n' || t == '\v' || t == '\f'
		|| t == '\r' || t == ' ');
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		mult;
	int		nb;

	mult = 1;
	nb = 0;
	i = 0;
	while (wspace(nptr[i]))
		i++;
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
