/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:09:43 by vpoirot           #+#    #+#             */
/*   Updated: 2023/06/08 15:07:42 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo_stc(t_philo *stc)
{
	free(stc->philo);
	free(stc);
}

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
	s_philo->philo = malloc(sizeof(int) * (s_philo->number + 1));
}

int	verif_info(t_philo *s_philo)
{
	if (s_philo->number < 1)
		return (1);
	return (0);
}

int	exit_error(char *str, t_philo *stc)
{
	write(1, "[ERROR] ", 8);
	write(1, str, ft_strlen(str));
	if (stc)
		free_philo_stc(stc);
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	*s_philo;

	if (argc < 5 || argc > 6)
		return (exit_error("Missing or too many parameters !\n", NULL));
	s_philo = malloc(sizeof(t_philo));
	if (!s_philo)
		return (0);
	grep_info(s_philo, argv);
	if (!s_philo->philo)
		return (free(s_philo), 0);
	if (verif_info(s_philo) == 1)
		return (exit_error("Wrong parameter !\n", s_philo));
	start_routine(s_philo);
	system("leaks philo");
	return (free(s_philo), 0);
}
