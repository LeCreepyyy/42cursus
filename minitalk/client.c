/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:01:55 by vpoirot           #+#    #+#             */
/*   Updated: 2023/04/05 10:55:16 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	bitchar(int pid, unsigned char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

static void	ft_reception(int sig, siginfo_t *client, void *none)
{
	(void)client;
	(void)none;
	if (sig == SIGUSR2)
		ft_putstr_fd("Message receive !\n", 1);
}

int	main(int argc, char **argv)
{
	int					i;
	int					pid;
	struct sigaction	sa;

	if (argc == 3)
	{
		i = 0;
		pid = ft_atoi(argv[1]);
		sa.sa_sigaction = ft_reception;
		sa.sa_flags = SA_SIGINFO | SA_RESTART;
		while (argv[2][i])
		{
			bitchar(pid, argv[2][i]);
			i++;
		}
		sigaction(SIGUSR2, &sa, NULL);
		bitchar(pid, '\0');
	}
	else
	{
		ft_putstr_fd("Arg error\n(HINT: ./client <pid> <message>)\n", 1);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
