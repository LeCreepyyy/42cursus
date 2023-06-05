/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:01:42 by vpoirot           #+#    #+#             */
/*   Updated: 2023/06/05 15:32:01 by vpoirot          ###   ########.fr       */
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

void	grep_move(char *line, int *a, int *b)
{
	if (line && ft_strncmp("sa\n", line, 3) == 0)
		s(a);
	else if (line && ft_strncmp("sb\n", line, 3) == 0)
		s(b);
	else if (line && ft_strncmp("pa\n", line, 3) == 0)
		p(a, b);
	else if (line && ft_strncmp("pb\n", line, 3) == 0)
		p(b, a);
	else if (line && ft_strncmp("ra\n", line, 3) == 0)
		r(a);
	else if (line && ft_strncmp("rb\n", line, 3) == 0)
		r(b);
	else if (line && ft_strncmp("rra\n", line, 4) == 0)
		r_r(a);
	else if (line && ft_strncmp("rrb\n", line, 4) == 0)
		r_r(b);
	else if (line && ft_strncmp("ss\n", line, 3) == 0)
		ss(a, b);
	else if (line && ft_strncmp("rr\n", line, 3) == 0)
		rotate_checker(a, b);
	else if (line && ft_strncmp("rrr\n", line, 4) == 0)
		rrotate_checker(a, b);
	else if (line)
		exit_failure();
}

void	ko_or_ok(int *a, int *b)
{
	if (is_sort(a) == 0 && b[0] == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(a);
	free(b);
}

int	main(int argc, char **argv)
{
	int		*a;
	int		*b;
	char	*line;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		argv = transform_arg(argv);
		argc = len_tab(argv);
	}
	if (argc < 3 || check_arg(argv, argc) == 0)
		exit_failure();
	a = create_a(argc, argv);
	b = create_b(argc);
	line = "none";
	while (line)
	{
		line = get_next_line(0);
		if (line && line[0] == '\n')
			break ;
		grep_move(line, a, b);
	}
	ko_or_ok(a, b);
	exit(EXIT_SUCCESS);
}
