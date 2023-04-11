/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:03:47 by vpoirot           #+#    #+#             */
/*   Updated: 2023/04/11 11:48:26 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*ft_free(char *str)
{
	free(str);
	str = 0;
	return (NULL);
}

char	*first_calloc(char *str, char c)
{
	str = ft_calloc(2, sizeof(char));
	if (!str)
		return (0);
	str[0] = c;
	return (str);
}

char	*strjoin_char(char	*str, unsigned char c)
{
	int		i;
	char	*new;

	if (!str)
		return (first_calloc(str, c));
	new = ft_calloc((ft_strlen(str) + 2), sizeof(char));
	if (!new)
	{
		free(str);
		return (0);
	}
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
		ft_free(str);
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
			str = ft_free(str);
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
