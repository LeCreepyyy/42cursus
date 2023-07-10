/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:36:12 by vpoirot           #+#    #+#             */
/*   Updated: 2023/07/10 14:56:52 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_philo *s_philo)
{
	int	i;

	i = -1;
	s_philo->m_fork = malloc(sizeof(pthread_mutex_t) * s_philo->number + 1);
	if (!s_philo->m_fork)
		return ;
	while (++i < s_philo->number)
		pthread_mutex_init(&(s_philo->m_fork[i]), NULL);
	pthread_mutex_init(&s_philo->m_print, NULL);
}

int	init_thread(t_philo *s_philo)
{
	int	i;

	i = 0;
	s_philo->s_info = malloc(sizeof(t_info) * s_philo->number);
	if (!s_philo->s_info)
		return (EXIT_FAILURE);
	while (++i <= s_philo->number)
	{
		s_philo->s_info[i - 1].rank = i;
		s_philo->s_info[i - 1].s_data = s_philo;
	}
	return (EXIT_SUCCESS);
}

void	erase_mutex(t_philo *s_philo)
{
	int	i;

	i = -1;
	while (++i != s_philo->number)
		pthread_mutex_destroy(&(s_philo->m_fork[i]));
}

void	waiting(t_philo *s_philo)
{
	int	i;

	i = -1;
	while (++i < s_philo->number)
		pthread_join(s_philo->s_info[i].thread, NULL);
}

void	start_routine(t_philo *s_philo)
{
	int		i;
	t_info	*thread;

	i = -1;
	init_mutex(s_philo);
	if (!s_philo->m_fork)
		return ;
	if (init_thread(s_philo))
		return (erase_mutex(s_philo));
	thread = s_philo->s_info;
	while (++i < s_philo->number)
		if (pthread_create(&thread[i].thread, NULL,
				&ft_routine, &s_philo->s_info[i]) != 0)
			return (erase_mutex(s_philo));
	death(s_philo);
	waiting(s_philo);
	erase_mutex(s_philo);
}
