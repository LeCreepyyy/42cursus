/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:18:46 by vpoirot           #+#    #+#             */
/*   Updated: 2023/06/02 14:56:28 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_push(int *a, int *b)
{
	int	i;

	i = 0;
	while (a[i] != 0 && i != (lenstack(a) / 2))
	{
		if (a[lenstack(a) - i] == get_min(a))
			break ;
		i++;
	}
	while (i < (lenstack(a) / 2) && a[0] != get_min(a))
		r_rotate(a, 'a');
	while (i == (lenstack(a) / 2) && a[0] != get_min(a))
		rotate(a, 'a');
	push(b, a, 'b');
}

void	get_push_b(int *b, int *a)
{
	int	i;
	int	size;

	i = -1;
	while (b[++i] != 0 && i != (lenstack(b) / 2))
		if (b[lenstack(b) - i] == get_max(b))
			break ;
	size = lenstack(b) / 2;
	while (i < size && b[0] != get_max(b))
	{
		if (b[0] == get_max(b) - 1)
			push(a, b, 'a');
		else
			r_rotate(b, 'b');
	}
	while (i == size && b[0] != get_max(b))
	{
		if (b[0] == get_max(b) - 1)
			push(a, b, 'a');
		else
			rotate(b, 'b');
	}
	push(a, b, 'a');
	if (a[1] && a[0] > a[1])
		swap(a, 'a');
}

void	r_sort_three(int *a)
{
	if (a[1] - a[0] == 1 && a[1] < a[2])
	{
		swap(a, 'a');
		r_rotate(a, 'a');
	}
	else if (a[1] - a[0] == -2)
	{
		swap(a, 'a');
		rotate(a, 'a');
	}
	else if (a[1] - a[0] == 1 && a[1] > a[2])
		swap(a, 'a');
	else if (a[1] - a[0] == 2)
		rotate(a, 'a');
	else if (a[1] - a[0] == -1)
		r_rotate(a, 'a');
}
