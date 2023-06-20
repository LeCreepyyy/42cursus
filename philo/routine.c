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

void	*ft_routine(void *arg)
{
	t_philo			*s_philo;

	s_philo = (t_philo *)arg;
	s_philo->m_fork = malloc(sizeof(pthread_mutex_t));
	while (s_philo->died == 0)
	{
		pthread_mutex_lock(s_philo->m_fork);
		take_fork(s_philo);
		pthread_mutex_unlock(s_philo->m_fork);
		pthread_mutex_lock(s_philo->m_fork);
		take_fork(s_philo);
		pthread_mutex_unlock(s_philo->m_fork);
		sleep(1);
		s_philo->died = 1;
	}
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
