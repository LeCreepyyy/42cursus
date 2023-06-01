/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:14:48 by vpoirot           #+#    #+#             */
/*   Updated: 2023/06/01 14:24:42 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(int *stack)
{
	int	temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}

void	r(int *tab)
{
	int	temp;
	int	i;

	i = 0;
	while (tab[++i] != 0)
	{
		temp = tab[i];
		tab[i] = tab[i - 1];
		tab[i - 1] = temp;
	}
}

void	r_r(int *tab)
{
	int	temp;
	int	i;

	i = lenstack(tab) - 1;
	while (i > 0)
	{
		temp = tab[i];
		tab[i] = tab[i - 1];
		tab[i - 1] = temp;
		i--;
	}
}

void	p(int *dest, int *stack)
{
	int	i;
	int	temp;

	i = (lenstack(dest));
	if (stack[0] == 0)
		return ;
	while (i > 0)
	{
		temp = dest[i];
		dest[i] = dest[i - 1];
		dest[i - 1] = temp;
		i--;
	}
	dest[0] = stack[0];
	stack[0] = 0;
	while (stack[i + 1] != 0)
	{
		temp = stack[i];
		stack[i] = stack[i + 1];
		stack[i + 1] = temp;
		i++;
	}
}
