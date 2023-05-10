/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:10:04 by vpoirot           #+#    #+#             */
/*   Updated: 2023/05/10 09:49:01 by vpoirot          ###   ########.fr       */
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

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}
