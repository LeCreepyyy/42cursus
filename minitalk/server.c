/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:03:47 by vpoirot           #+#    #+#             */
/*   Updated: 2023/03/29 11:24:14 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigusr1(int sig)
{
	ft_printf("Coucou les loulous.\n");
	(void)sig;
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("%d\n", getpid());
	sa.sa_handler = &handle_sigusr1;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
		;
	return (0);
}
