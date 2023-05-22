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

/*
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
*/

void sort(int *stack_a, int *stack_b)
{
    int min;
    int max;
    int size;
    int i = 0;
    int j;

    size = lenstack(stack_a);
    while (!is_sort(stack_a))
    {
        min = stack_a[0];
        max = stack_a[0];
        j = 0;
        while (j < size)
        {
            if (stack_a[j] < min)
                min = stack_a[j];
            if (stack_a[j] > max)
                max = stack_a[j];
            j++;
        }
        if (stack_a[0] != min && stack_a[size - 1] != min)
            while (stack_a[0] != min)
                rotate(stack_a, 'a');
        if (stack_a[0] != min)
            swap(stack_a, 'a');
        push(stack_b, stack_a, 'b');
        if (stack_a[0] == max)
            swap(stack_a, 'a');
        else
            while (stack_a[0] != max)
                r_rotate(stack_a, 'a');
        push(stack_a, stack_b, 'a');
        i++;
    }
}
