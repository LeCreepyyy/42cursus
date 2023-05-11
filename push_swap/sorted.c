/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:59:26 by vpoirot           #+#    #+#             */
/*   Updated: 2023/05/11 13:01:47 by vpoirot          ###   ########.fr       */
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
/*
1 2 3
1 3 2
2 1 3
2 3 1
3 2 1
3 1 2
*/
