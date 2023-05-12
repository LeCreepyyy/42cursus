/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:59:26 by vpoirot           #+#    #+#             */
/*   Updated: 2023/05/12 13:17:26 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(int	*stack)
{
	int	i;

	i = 0;
	while (stack[i + 1] != 0)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	get_max(int *stack)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (stack[i] != 0)
	{
		if (stack[i] > max)
			max = stack[i];
		i++;
	}
	return (max);
}

int	get_min(int *stack)
{
	int	i;
	int	min;

	i = 0;
	min = stack[0];
	while (stack[i] != 0)
	{
		if (stack[i] < min)
			min = stack[i];
		i++;
	}
	return (min);
}

void	sort_three(int *a)
{
	if (is_sort(a) == 1)
		return ;
	if (a[0] - a[1] == 1 && a[1] > a[2])
	{
		swap(a, 'a');
		r_rotate(a, 'a');
	}
	else if (a[0] - a[1] == -2)
	{
		swap(a, 'a');
		rotate(a, 'a');
	}
	else if (a[0] - a[1] == 1 && a[1] < a[2])
		swap(a, 'a');
	else if (a[0] - a[1] == 2)
		rotate(a, 'a');
	else if (a[0] - a[1] == -1)
		r_rotate(a, 'a');
}

void	little_algo(int *a, int *b)
{
	int	size;

	size = lenstack(a);
	if (size - 3 == 2)
		get_push(a, b);
	get_push(a, b);
	sort_three(a);
	if (size - 3 == 2)
		push(a, b, 'a');
	push(a, b, 'a');
}
