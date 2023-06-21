/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:01:35 by vpoirot           #+#    #+#             */
/*   Updated: 2023/06/21 13:10:20 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_philo *s_philo)
{
	if (s_philo->s_info)
		free(s_philo->s_info);
	if (s_philo->m_fork)
		free(s_philo->m_fork);
}

void	check_arg(int i)
{
	if (i == 1)
		printf("%s<Count of philo> %s%dst arg !\n", RED, YELLOW, i);
	else if (i == 2)
		printf("%s<Time to die> %s%dnd arg !\n", RED, YELLOW, i);
	else if (i == 3)
		printf("%s<Time to eat> %s%drd arg !\n", RED, YELLOW, i);
	else if (i == 4)
		printf("%s<Time to sleep> %s%dth arg !\n", RED, YELLOW, i);
}

int	argv_len(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	exit_error(t_philo *stc, char **argv, char *err)
{
	int	i;

	if (argv_len(argv) > 6)
	{
		printf("%s[ERROR]%s Too many arg !\n", RED, YELLOW);
		return (0);
	}
	printf("%s[ERROR]%s %s", RED, YELLOW, err);
	i = -1;
	while (++i < 5)
	{
		if (!argv[i])
		{
			check_arg(i);
			break ;
		}
	}
	if (stc)
		free(stc);
	return (0);
}
