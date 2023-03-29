/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:01:55 by vpoirot           #+#    #+#             */
/*   Updated: 2023/03/29 14:19:20 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// argv[2] = str

int	main(int argc, char **argv)
{
	int	pid;

	if (argc <= 1)
		return (EXIT_FAILURE);
	pid = ft_atoi(argv[1]);
	ft_printf("Client launch.\n");
	kill(pid, SIGUSR1);
	return (EXIT_SUCCESS);
}
