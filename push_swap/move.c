/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:24:20 by vpoirot           #+#    #+#             */
/*   Updated: 2023/05/10 15:11:17 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *stack)
{
	int	temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}

void	s_swap(int a, int *b)
{
	swap(a);
	swap(b);
	write(1, "ss", 2);
}

// ↑ up rotate
void	rotate(int *tab)
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

void	r_rotate(int *tab)
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

void	push(int *dest, int *stack)
{
	int	i;
	int	temp;

	i = (lenstack(dest) + 1);
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
