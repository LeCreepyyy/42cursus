/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:01:55 by vpoirot           #+#    #+#             */
/*   Updated: 2023/03/31 09:34:47 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bitchar(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >> 3) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ft_printf("Client launch.\n");
		bitchar(pid, argv[2]);
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_printf("Arguments error\n");
		return (EXIT_FAILURE);
	}
}
