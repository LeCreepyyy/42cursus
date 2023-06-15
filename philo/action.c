/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:20:27 by vpoirot           #+#    #+#             */
/*   Updated: 2023/06/15 14:37:42 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *s_philo, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	s_philo->fork--;
	pthread_mutex_unlock(mutex);
	write(1, ft_itoa(s_philo->philo), 1);
	write(1, " has taken a fork\n", 18);
	s_philo->philo++;
}
