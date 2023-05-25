/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:19:38 by vpoirot           #+#    #+#             */
/*   Updated: 2023/05/25 13:40:58 by vpoirot          ###   ########.fr       */
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

void	spliter(int	*b, int add, int split)
{
	int	limit;

	limit = split - (add / 2);
	if (b[0] > limit)
		rotate(b, 'b');
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
		{
			push(b, a, 'b');
			spliter(b, add, split);
		}
		else
			rotate(a, 'a');
		if (!find_nbr(a, split))
			split += add;
	}
	while (a[0])
		push(b, a, 'b');
	while (b[0])
		get_push_b(b, a);
}

void	check_size(int *a, int *b)
{
	if (lenstack(a) <= 100)
		big_sort(a, b, 4);
	else if (lenstack(a) <= 500)
		big_sort(a, b, 8);
	else if (lenstack(a) > 500)
		big_sort(a, b, 12);
}
