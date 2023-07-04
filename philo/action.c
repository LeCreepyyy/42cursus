/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:20:27 by vpoirot           #+#    #+#             */
/*   Updated: 2023/07/04 14:39:31 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_info *s_info)
{
	int		i;

	if (s_info->rank == s_info->s_data->number)
		i = 0;
	else
		i = s_info->rank;
	pthread_mutex_lock(&s_info->s_data->m_fork[s_info->rank - 1]);
	mutex_print("has taken a fork", s_info->rank, s_info->s_data);
	pthread_mutex_lock(&s_info->s_data->m_fork[i]);
	mutex_print("has taken a fork", s_info->rank, s_info->s_data);
	mutex_print("is eating", s_info->rank, s_info->s_data);
	usleep(s_info->s_data->eat);
	pthread_mutex_unlock(&s_info->s_data->m_fork[s_info->rank - 1]);
	pthread_mutex_unlock(&s_info->s_data->m_fork[i]);
}
