/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:02:33 by vpoirot           #+#    #+#             */
/*   Updated: 2023/06/05 15:31:24 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*a;
	int		*b;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		argv = transform_arg(argv);
		argc = len_tab(argv);
	}
	if (argc == 2)
		exit(EXIT_SUCCESS);
	if (argc < 3 || check_arg(argv, argc) == 0)
		exit_failure();
	a = create_a(argc, argv);
	b = create_b(argc);
	if (argc <= 6)
		little_algo(a, b);
	else if (is_sort(a) != 0)
		check_size(a, b);
	free(a);
	free(b);
	exit(EXIT_SUCCESS);
}
