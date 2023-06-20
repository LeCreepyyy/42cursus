/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:09:43 by vpoirot           #+#    #+#             */
/*   Updated: 2023/06/20 14:21:18 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	grep_info(t_philo *s_philo, char **argv)
{
	s_philo->number = ft_atoi(argv[1]);
	s_philo->death_time = ft_atoi(argv[2]);
	s_philo->eat = ft_atoi(argv[3]);
	s_philo->sleep = ft_atoi(argv[4]);
	s_philo->limit = -1;
	if (argv[5])
		s_philo->limit = ft_atoi(argv[5]);
	s_philo->fork = s_philo->number;
	s_philo->philo = 1;
}

int	main(int argc, char **argv)
{
	t_philo	*s_philo;

	if (argc < 5 || argc > 6)
		return (exit_error(NULL, argv, "Missing arg :"));
	s_philo = malloc(sizeof(t_philo));
	if (!s_philo)
		return (0);
	grep_info(s_philo, argv);
	if (s_philo->number < 1)
		return (exit_error(s_philo, argv, "Count of philo is to lower\n"));
	start_routine(s_philo);
	return (free(s_philo), 0);
}
