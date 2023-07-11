/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:45:09 by marvin            #+#    #+#             */
/*   Updated: 2023/07/11 13:30:50 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(int time)
{
	int	begin;
	int	current;

	current = 0;
	begin = timestamp();
	while (current < time)
	{
		usleep(200);
		current = timestamp() - begin;
	}
}

void	*ft_routine(void *arg)
{
	t_info	*s_info;

	s_info = (t_info *)arg;
	pthread_mutex_init(&s_info->m_eat, NULL);
	if (s_info->rank % 2 == 0)
		ft_usleep(s_info->s_data->eat);
	s_info->l_eat = 0;
	while (s_info->s_data->died == 0)
	{
		if (s_info->s_data->limit > 0 && s_info->l_eat == s_info->s_data->limit)
			return (NULL);
		take_fork(s_info);
		sleeping(s_info);
		mutex_print("is thinking", s_info->rank, s_info->s_data, YELLOW);
	}
	return (NULL);
}
