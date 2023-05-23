/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:19:38 by vpoirot           #+#    #+#             */
/*   Updated: 2023/05/23 15:02:58 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_nbr(int *stack, int limit)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		if (stack[i] < limit)
			return (1);
		i++;
	}
	return (0);
}

void	big_sort(int *a, int *b, int package)
{
	int	split;
	int	add;
	int	size;

	size = lenstack(a);
	add = size / package;
	split = add;
	while (split <= size)
	{
		if (a[0] < split)
			push(b, a, 'b');
		else
			rotate(a, 'a');
		if (!find_nbr(a, split))
			split += add;
	}
	while (b[0])
		get_push_b(b, a);
}

void	check_size(int *a, int *b)
{
	big_sort(a, b, 8);
}
