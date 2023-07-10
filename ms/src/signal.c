/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:57:20 by vpoirot           #+#    #+#             */
/*   Updated: 2023/06/26 15:37:11 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	handle_sigquit(int sig, siginfo_t *none, void *useless)
{
	(void)sig;
	(void)none;
	(void)useless;
	printf("minishell $> exit\n");
	exit(EXIT_SUCCESS);
}

void	handle_sigint(int sig, siginfo_t *none, void *useless)
{
	char	c;

	c = 10;
	(void)sig;
	(void)none;
	(void)useless;
	write(0, &c, 1);
	write(0, "minishell $> ", 13);
	//readline("minishell $> ");
}

void	init_signal(void)
{
	struct sigaction	sigint;
	struct sigaction	sigquit;

	sigint.sa_sigaction = handle_sigint;
	sigint.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&(sigint.sa_mask));
	sigaction(SIGINT, &sigint, NULL);
	sigquit.sa_sigaction = handle_sigquit;
	sigquit.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&(sigquit.sa_mask));
	sigaction(SIGQUIT, &sigquit, NULL);
}
