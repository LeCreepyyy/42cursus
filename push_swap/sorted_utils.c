/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:18:46 by vpoirot           #+#    #+#             */
/*   Updated: 2023/05/12 11:25:32 by vpoirot          ###   ########.fr       */
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
