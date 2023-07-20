/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:09:43 by vpoirot           #+#    #+#             */
/*   Updated: 2023/07/20 14:27:28 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	grep_info(t_philo *s_philo, char **argv)
{
	int	i;

	s_philo->number = ft_atoi(argv[1]);
	s_philo->death_time = ft_atoi(argv[2]);
	s_philo->eat = ft_atoi(argv[3]);
	s_philo->sleep = ft_atoi(argv[4]);
	s_philo->limit = -1;
	if (argv[5])
		s_philo->limit = ft_atoi(argv[5]);
	else
		s_philo->limit = -1;
	s_philo->beginning = timestamp();
	s_philo->died = 0;
	s_philo->global_eat = 0;
	i = -1;
}

int	verif_arg(char **argv, t_philo *s_philo)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		if (ft_strlen(argv[i]) > ft_strlen("2147483647"))
			return (1);
		while (argv[i][++j])
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
	}
	if (s_philo->death_time <= 0 || s_philo->eat <= 0
		|| s_philo->sleep <= 0 || s_philo->limit <= -2
		|| s_philo->number <= 0)
		return (1);
	return (0);
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
	if (verif_arg(argv, s_philo) == 1 && printf("Arg invalid !\n"))
		return (0);
	if (s_philo->number == 1)
	{
		printf("0 1 has taken a fork\n");
		usleep(s_philo->death_time);
		printf("%d 1 is dead\n", s_philo->death_time + 1);
		return (0);
	}
	start_routine(s_philo);
	ft_free(s_philo);
	return (0);
}
