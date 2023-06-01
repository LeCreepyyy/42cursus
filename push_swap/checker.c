/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:01:42 by vpoirot           #+#    #+#             */
/*   Updated: 2023/06/01 14:41:22 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(int	*a, int *b)
{
	int	i;

	i = 0;
	while (a[i] != 0 || b[i] != 0)
	{
		printf("%d\t", a[i]);
		printf("%d\n", b[i]);
		i++;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == 0)
			return (0);
		i++;
	}
	return (0);
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
	while (is_sort(a) == 1 && b[0] == 0)
	{
		if (ft_strncmp("sa\n", get_next_line(STDIN_FILENO), 3) == 0)
			s(a);
	}
	exit(EXIT_SUCCESS);
}
