/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:01:55 by vpoirot           #+#    #+#             */
/*   Updated: 2023/03/30 13:52:50 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ft_printf("Client launch.\n");
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_printf("Arguments error\n");
		return (EXIT_FAILURE);
	}
}
