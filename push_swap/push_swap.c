/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:02:33 by vpoirot           #+#    #+#             */
/*   Updated: 2023/05/04 13:29:23 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_int(int argc, int *pile)
{
	while (argc)
	{
		argc--;
	}
	return (0);
}

int	*arg_int(int argc, char **argv)
{
	int	*pile;
	int	i;

	pile = malloc((argc + 1) * sizeof(int));
	if (!pile)
		return (0);
	i = 1;
	while (argv[i])
	{
		pile[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	pile = sort_int(argc, pile);
	return (pile);
}

int	main(int argc, char **argv)
{
	int	*a;

	if (argc < 2 || check_arg(argv, argc) == 0)
		return (0);
	a = arg_int(argc - 1, argv);
	return (0);
}
