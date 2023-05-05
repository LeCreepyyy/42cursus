/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:02:33 by vpoirot           #+#    #+#             */
/*   Updated: 2023/05/05 14:36:33 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(int *stack)
{
	int	i;

	i = 0;
	while (stack[i] != 0)
	{
		printf("%d\n", stack[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	*a;
	int	*b;

	if (argc < 2 || check_arg(argv, argc) == 0)
		return (0);
	a = create_a(argc, argv);
	b = create_b(argc);
	print_stack(a);
	return (0);
}
