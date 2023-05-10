/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:02:33 by vpoirot           #+#    #+#             */
/*   Updated: 2023/05/10 11:08:38 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(int *stack, int *b)
{
	int	i;

	i = 0;
	while (stack[i] != 0 || b[i] != 0)
	{
		printf("%d\t", stack[i]);
		printf("%d\n", b[i]);
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
	print_stack(a, b);
	printf("\n\n");
	print_stack(a, b);
	return (0);
}
