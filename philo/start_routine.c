/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:36:12 by vpoirot           #+#    #+#             */
/*   Updated: 2023/06/20 15:30:02 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_philo *s_philo)
{
	int	i;

	i = -1;
	s_philo->m_fork = malloc(sizeof(pthread_mutex_t) * s_philo->number);
	if (!s_philo->m_fork)
		return ;
	while (++i < s_philo->number)
		pthread_mutex_init(&(s_philo->m_fork[i]), NULL);
}

int	init_thread(t_philo *s_philo)
{
	int	i;

	i = 0;
	s_philo->s_info = malloc(sizeof(t_info));
	if (!s_philo->s_info)
		return (EXIT_FAILURE);
	while (++i < s_philo->number)
		s_philo->s_info->rank = i;
	return (EXIT_SUCCESS);
}

void	erase_mutex(t_philo *s_philo)
{
	int	i;

	i = -1;
	while (++i != s_philo->number)
		pthread_mutex_destroy(&(s_philo->m_fork[i]));
}

void	erase_thread(t_philo *s_philo)
{
	int	i;

	i = -1;
	while (++i < s_philo->number)
	{
		pthread_join(s_philo->s_info[i].thread, NULL);
	}
	
}

void	start_routine(t_philo *s_philo)
{
	int		i;
	t_info	*thread;

	i = -1;
	thread = s_philo->s_info;
	init_mutex(s_philo);
	if (!s_philo->m_fork)
		return ;
	if (init_thread(s_philo))
		return (erase_mutex(s_philo));
	while (++i < s_philo->number)
		pthread_create(&(thread[i].thread), NULL, &ft_routine, s_philo);
	erase_mutex(s_philo);
	erase_thread(s_philo);
}
