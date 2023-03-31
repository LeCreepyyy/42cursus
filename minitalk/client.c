/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:01:55 by vpoirot           #+#    #+#             */
/*   Updated: 2023/03/31 13:53:25 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bitchar(int pid, char c)
{
	int	bit;

	bit = 8;
	while (bit-- >= 0)
	{
		if ((c >> 3) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc == 3)
	{
		i = 0;
		pid = ft_atoi(argv[1]);
		ft_printf("Client launch.\n");
		while (argv[2][i++])
			bitchar(pid, argv[2][i]);
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_printf("Arguments error\n");
		return (EXIT_FAILURE);
	}
}
