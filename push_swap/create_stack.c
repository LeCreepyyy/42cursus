/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:28:11 by vpoirot           #+#    #+#             */
/*   Updated: 2023/05/10 11:08:27 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	return_nbr(int nb, int *stack, int argc)
{
	int	i;

	i = 1;
	while (argc >= 0)
	{
		if (stack[argc] < nb)
			i++;
		argc--;
	}
	return (i);
}

int	*sort_int(int argc, int *stack)
{
	int	i;
	int	*res;

	i = argc;
	res = malloc((argc + 1) * sizeof(int));
	if (!res)
		return (0);
	while (i >= 0)
	{
		res[i] = return_nbr(stack[i], stack, (argc - 1));
		i--;
	}
	res[argc] = 0;
	free(stack);
	return (res);
}

int	*create_a(int argc, char **argv)
{
	int	*stack;
	int	i;

	stack = malloc((argc + 1) * sizeof(int));
	if (!stack)
		return (0);
	i = 1;
	while (i < argc)
	{
		stack[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	stack[i - 1] = 0;
	stack = sort_int(argc - 1, stack);
	return (stack);
}

int	*create_b(int argc)
{
	int	*b;

	b = malloc(sizeof(int) * argc--);
	if (!b)
		return (0);
	while (argc >= 0)
	{
		b[argc] = 0;
		argc--;
	}
	return (b);
}
