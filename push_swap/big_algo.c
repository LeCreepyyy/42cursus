/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:19:38 by vpoirot           #+#    #+#             */
/*   Updated: 2023/05/22 13:39:23 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	visual_tab(int *stack, int nbr)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		if (stack[i] < nbr)
			return (1);
		i++;
	}
	return (0);
}

void	big_sort(int *a, int *b, int x)
{
	int	size;
	int	i;

	i = 1;
	size = lenstack(a);
	while (i <= x)
	{
		if (a[0] <= size / i)
			push(b, a, 'b');
		else
			rotate(a, 'a');
		if (visual_tab(a, size / i) == 0)
			i++;
	}
}

void	check_size(int *a, int *b)
{
	big_sort(a, b, 4);
}
