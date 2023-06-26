/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:20:27 by vpoirot           #+#    #+#             */
/*   Updated: 2023/06/26 12:25:39 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *s_philo, int i)
{
	pthread_mutex_lock(&s_philo->m_fork[s_philo->s_info[i].rank]);
	printf("%d has taken a fork\n", s_philo->s_info[i].rank);
	pthread_mutex_lock(&s_philo->m_fork[s_philo->s_info[i + 1].rank]);
	printf("%d has taken a fork\n", s_philo->s_info[i].rank);
	printf("%d is eating\n", s_philo->s_info[i].rank);
	sleep(1);
	pthread_mutex_unlock(&s_philo->m_fork[s_philo->s_info[i].rank]);
	pthread_mutex_unlock(&s_philo->m_fork[s_philo->s_info[i + 1].rank]);
}

/*
	pthread_mutex_lock(s_philo->m_fork);
	printf("%d has taken a fork\n", s_philo->s_info[i].rank);
	i++;
	pthread_mutex_unlock(s_philo->m_fork);
*/
