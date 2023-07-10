/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:09:28 by vpoirot           #+#    #+#             */
/*   Updated: 2023/06/26 16:20:20 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

#define READLINE_DLL_IMPEXP 0

void	write_env(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		printf("%s\n", env[i]);
}

int	main(int argc, char **argv, char **env)
{
	char	*input;

	(void)argc;
	(void)argv;
	init_signal();
	while (1)
	{
		input = readline("minishell $> ");
		if (ft_strcmp(input, "exit") == 0)
			return (printf("exit\n"));
		else if (ft_strcmp(input, "env") == 0)
			write_env(env);
		else if (ft_strcmp(input, "") == 0)
			;
		else
			printf("bash: %s: command not found\n", input);
	}
	return (0);
}
