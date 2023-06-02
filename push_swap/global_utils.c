/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:34:59 by vpoirot           #+#    #+#             */
/*   Updated: 2023/06/02 13:42:29 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_two_arg(int *a)
{
	if (a[0] > a[1])
		swap(a, 'a');
	return ;
}

void	exit_failure(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

char	**transform_arg(char **argv)
{
	argv[1] = ft_strjoin_n("none ", argv[1]);
	if (!argv[1])
		exit_failure();
	argv = ft_split(argv[1], ' ');
	if (!argv)
		exit_failure();
	return (argv);
}
