/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:02:33 by vpoirot           #+#    #+#             */
/*   Updated: 2023/05/25 13:19:10 by vpoirot          ###   ########.fr       */
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

void	exit_failure(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	print_tab(char **tab)
{
	int i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

char	**transform_arg(char **argv)
{
	argv[1] = ft_strjoin("none ", argv[1]);
	if (!argv[1])
		exit_failure();
	argv = ft_split(argv[1], ' ');
	if (!argv)
		exit_failure();
	return (argv);
}

int	main(int argc, char **argv)
{
	int		*a;
	int		*b;

	if (argc == 2)
	{
		argv = transform_arg(argv);
		argc = len_tab(argv);
	}
	if (argc < 3 || check_arg(argv, argc) == 0)
		exit_failure();
	a = create_a(argc, argv);
	b = create_b(argc);
	// print_stack(a, b);
	if (argc <= 6)
		little_algo(a, b);
	else
		check_size(a, b);
	// print_stack(a, b);
	exit(EXIT_SUCCESS);
}
