/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:10:04 by vpoirot           #+#    #+#             */
/*   Updated: 2023/05/25 13:18:52 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *nb)
{
	long	n;
	int		i;
	int		mult;

	i = 0;
	n = 0;
	mult = 1;
	if (nb[i] == '-')
	{
		mult = -1;
		i++;
	}
	while (nb[i])
	{
		n = (n * 10) + (nb[i] - 48);
		i++;
	}
	n *= mult;
	return (n);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	sz;

	sz = 0;
	while (src[sz])
		sz++;
	if (dstsize == 0)
		return (sz);
	i = 0;
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (sz);
}

int	len_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	lenstack(int *tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
