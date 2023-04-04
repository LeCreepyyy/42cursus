/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:03:47 by vpoirot           #+#    #+#             */
/*   Updated: 2023/04/04 10:38:29 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigusr(int sig)
{
	static int				bit;
	static unsigned char	c;

	if (bit < 0)
		bit = 7;
	if (sig == SIGUSR1)
		c |= (1 << bit);
	bit--;
	if (bit < 0)
	{
		ft_printf("%c", c);
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("%d\n", getpid());
	sa.sa_handler = &handle_sigusr;
	sa.sa_flags = SA_RESTART;
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
	return (0);
}
