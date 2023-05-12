/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:18:46 by vpoirot           #+#    #+#             */
/*   Updated: 2023/05/12 15:26:44 by vpoirot          ###   ########.fr       */
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

void	mid_algo(int *a, int *b)
{
	int	i;
	int	save;

	save = 0;
	while (lenstack(a) >= 3)
	{
		i = 3;
		while (--i >= 0)
			get_push(a, b);
		if (b[(lenstack(b) - save) + 1] != 0)
		{
			i = 0;
			while (--i >= 0)
				get_push(b, a);
		}
		save += 3;
		sort_three(b);
	}
	if (a[0] != 0 && a[0] > a[1])
		swap(a, 'a');
	while (b[0] != 0)
		push(a, b, 'a');
}
