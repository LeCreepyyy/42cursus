/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:45:09 by marvin            #+#    #+#             */
/*   Updated: 2023/07/06 10:05:58 by vpoirot          ###   ########.fr       */
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
	if (s_info->rank % 2 == 0)
		ft_usleep(100);
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