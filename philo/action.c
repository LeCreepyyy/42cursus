/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:20:27 by vpoirot           #+#    #+#             */
/*   Updated: 2023/06/20 13:01:20 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *s_philo)
{
	s_philo->fork--;
	printf("%d has taken a fork\n", s_philo->philo);
	s_philo->philo++;
}
