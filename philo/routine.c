/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:36:12 by vpoirot           #+#    #+#             */
/*   Updated: 2023/06/15 14:56:30 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	erase_mutex(t_mutex *s_mutex)
{
	pthread_mutex_destroy(s_mutex->m_fork);
	free(s_mutex);
}

void	init_mutex(t_mutex *s_mutex)
{
	s_mutex->m_fork = malloc(sizeof(pthread_mutex_t));
	if (!s_mutex->m_fork)
		return ;
	pthread_mutex_init(s_mutex->m_fork, NULL);
}

void	*ft_routine(void *arg)
{
	t_philo	*s_philo;
	t_mutex	*s_mutex;

	s_mutex = malloc(sizeof(t_mutex));
	init_mutex(s_mutex);
	s_philo = (t_philo *)arg;
	while (s_philo->died == 0)
	{
		if (s_philo->fork >= 2)
			take_fork(s_philo, s_mutex->m_fork);
		s_philo->died = 1;
	}
	erase_mutex(s_mutex);
	return (NULL);
}

void	erase_thread(pthread_t *philo, t_philo *s_philo)
{
	int	i;

	i = 0;
	while (s_philo->philo >= 0)
	{
		pthread_join(philo[s_philo->philo], NULL);
		s_philo->philo--;
	}
}

void	start_routine(t_philo *s_philo)
{
	int			i;
	pthread_t	*philo;

	i = -1;
	philo = malloc(sizeof(pthread_t) * s_philo->number);
	if (!philo)
		return ;
	while (++i < s_philo->number)
		pthread_create(&philo[i], NULL, &ft_routine, s_philo);
	s_philo->died = 0;
	while (s_philo->died != 1)
		;
	erase_thread(philo, s_philo);
}
