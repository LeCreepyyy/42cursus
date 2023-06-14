/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:20:27 by vpoirot           #+#    #+#             */
/*   Updated: 2023/06/14 13:50:02 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *s_philo)
{
	if (s_philo->fork < 2)
		return ;
	if (s_philo->philo == (s_philo->number + 1))
		s_philo->philo = 1;
	s_philo->fork -= 2;
	write(1, ft_itoa(s_philo->philo), 1);
	write(1, " has taken a fork\n", 18);
	write(1, ft_itoa(s_philo->philo), 1);
	write(1, " is eating\n", 11);
	usleep(s_philo->eat);
	s_philo->philo++;
}
