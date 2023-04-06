/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:39:41 by vpoirot           #+#    #+#             */
/*   Updated: 2023/04/06 12:29:53 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbr_count(unsigned int n)
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
	return (i);
}

static char	*ft_return_nbr(char *str, unsigned int nb, int size)
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
	return (str);
}

int	ft_itoa_uns(unsigned int n)
{
	char	*str;
	int		tmp;

	str = malloc(sizeof(char) * (ft_nbr_count(n) + 1));
	if (str == 0)
		return (-1);
	else
		str = ft_return_nbr(str, n, ft_nbr_count(n));
	tmp = write(1, str, ft_strlen(str));
	free(str);
	return (tmp);
}
