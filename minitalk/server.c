/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:03:47 by vpoirot           #+#    #+#             */
/*   Updated: 2023/04/06 12:40:52 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*strjoin_char(char	*str, unsigned char c)
{
	int		i;
	char	*new;

	if (!str)
	{
		str = ft_calloc(2, sizeof(char));
		str[0] = c;
		return (str);
	}
	new = ft_calloc((ft_strlen(str) + 2), sizeof(char));
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	if (c != '\0')
	{
		new[i] = c;
		i++;
	}
	if (str)
		free(str);
	return (new);
}

void	handle_sigusr(int sig, siginfo_t *client, void *useless)
{
	static int				bit;
	static unsigned char	c;
	static char				*str;

	(void)useless;
	if (sig == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (c == 0)
		{
			ft_putstr_fd(str, 1);
			kill(client->si_pid, SIGUSR2);
		}
		str = strjoin_char(str, c);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putnbr(getpid());
	write(1, "\n", 1);
	sa.sa_sigaction = handle_sigusr;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&(sa.sa_mask));
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
