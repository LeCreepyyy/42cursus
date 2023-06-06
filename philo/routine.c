/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:36:12 by vpoirot           #+#    #+#             */
/*   Updated: 2023/06/06 15:44:44 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *s_philo)
{
	(void)s_philo;
	printf("Thread created\n");
	return (NULL);
}

void	erase_thread(pthread_t *philo, int i)
{
	while (i > 0)
	{
		pthread_join(philo[i], NULL);
		i--;
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
	{
		if (pthread_create(&philo[i], NULL, &ft_routine, s_philo) != 0)
			return ;
	}
	printf("test\n");
	erase_thread(philo, i);
}
