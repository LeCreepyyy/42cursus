/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:08:14 by vpoirot           #+#    #+#             */
/*   Updated: 2023/05/15 14:10:58 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_valid(char **arg)
{
	int	i;
	int	j;

	i = 1;
	while (arg[i])
	{
		j = -1;
		if (arg[i][j + 1] == '-')
			j = 0;
		while (arg[i][++j])
			if ((arg[i][j] < '0' || arg[i][j] > '9'))
				return (0);
		i++;
	}
	return (1);
}

int	int_cmp(char **arg)
{
	int		i;
	long	n;

	i = 1;
	while (arg[i])
	{
		n = ft_atoi(arg[i]);
		if (n > 2147483647 || n < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	*set_arg_number(char **arg, int count)
{
	int	i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * (count - 1));
	if (!tab)
		return (0);
	while (arg[i + 1])
	{
		tab[i] = ft_atoi(arg[i + 1]);
		i++;
	}
	return (tab);
}

int	find_double(int	*tab, int count)
{
	int	i;
	int	j;

	i = 0;
	count--;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_arg(char **arg, int count)
{
	int	*tab;

	if (number_valid(arg) == 0)
		return (0);
	if (int_cmp(arg) == 0)
		return (0);
	tab = set_arg_number(arg, count);
	if (find_double(tab, count) == 0)
		return (0);
	return (free(tab), 1);
}
