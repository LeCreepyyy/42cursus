/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:18:46 by vpoirot           #+#    #+#             */
/*   Updated: 2023/05/15 15:20:00 by vpoirot          ###   ########.fr       */
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

void	get_push_max(int *a, int *b)
{
	int	i;

	i = 0;
	while (a[i] != 0 && i != (lenstack(a) / 2))
	{
		if (a[lenstack(a) - i] == get_max(a))
			break ;
		i++;
	}
	while (i < (lenstack(a) / 2) && a[0] != get_max(a))
		r_rotate(a, 'a');
	while (i == (lenstack(a) / 2) && a[0] != get_max(a))
		rotate(a, 'a');
	push(b, a, 'b');
}

void	is_two_arg(int *a)
{
	if (a[0] > a[1])
		swap(a, 'a');
	return ;
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
