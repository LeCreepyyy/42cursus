/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:20:27 by vpoirot           #+#    #+#             */
/*   Updated: 2023/07/10 14:56:06 by vpoirot          ###   ########.fr       */
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
	mutex_print("has taken a fork", s_info->rank, s_info->s_data, 0);
	pthread_mutex_lock(&s_info->s_data->m_fork[i]);
	mutex_print("has taken a fork", s_info->rank, s_info->s_data, 0);
	mutex_print("is eating", s_info->rank, s_info->s_data, SKY);
	ft_usleep(s_info->s_data->eat);
	s_info->time_eat = timestamp();
	pthread_mutex_unlock(&s_info->s_data->m_fork[s_info->rank - 1]);
	pthread_mutex_unlock(&s_info->s_data->m_fork[i]);
	s_info->l_eat++;
}

void	sleeping(t_info *s_info)
{
	mutex_print("is sleeping", s_info->rank, s_info->s_data, GRAY);
	ft_usleep(s_info->s_data->sleep);
}

void	death(t_philo *s_philo)
{
	int	i;

	while (s_philo->died == 0)
	{
		i = 0;
		while (&s_philo->s_info[i] && s_philo->died == 0)
		{
			if ((timestamp() - s_philo->s_info[i].time_eat)
				> s_philo->death_time)
			{
				s_philo->died = 1;
				mutex_print("is dead", s_philo->s_info[i].rank, s_philo, RED);
			}
			i++;
		}
	}
}
