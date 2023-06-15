/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:36:12 by vpoirot           #+#    #+#             */
/*   Updated: 2023/06/15 12:34:27 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *arg)
{
	t_philo			*s_philo;
	pthread_mutex_t	*mutex;

	s_philo = (t_philo *)arg;
	mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(mutex, NULL);
	while (s_philo->died == 0)
	{
		pthread_mutex_lock(mutex);
		take_fork(s_philo);
		pthread_mutex_unlock(mutex);
		s_philo->died = 1;
	}
	pthread_mutex_destroy(mutex);
	return (NULL);
}

void	erase_thread(pthread_t *philo)
{
	int	i;

	i = 0;
	while (philo[i])
	{
		pthread_join(philo[i], NULL);
		printf("%d\n", i);
		i++;
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
	erase_thread(philo);
}
