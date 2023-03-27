/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:58:12 by vpoirot           #+#    #+#             */
/*   Updated: 2022/12/21 12:49:58 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_nbr_count(int n, int sig)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	if (sig == -1)
		i++;
	return (i);
}

static char	*ft_return_nbr(char *str, int nb, int size, int sig)
{
	int	i;

	i = 0;
	str[size] = 0;
	str[--size] = nb % 10 + '0';
	nb /= 10;
	while (nb > 0)
	{
		str[--size] = nb % 10 + '0';
		nb /= 10;
	}
	if (sig == -1)
		str[0] = '-';
	return (str);
}

int	ft_itoa(int n)
{
	char	*str;
	int		sig;
	int		tmp;

	sig = 1;
	if (n < 0)
	{
		sig = -1;
		n *= -1;
	}
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	str = malloc(sizeof(char) * (ft_nbr_count(n, sig) + 1));
	if (str == 0)
		return (-1);
	else
		str = ft_return_nbr(str, n, ft_nbr_count(n, sig), sig);
	tmp = write(1, str, ft_strlen(str));
	free(str);
	return (tmp);
}
