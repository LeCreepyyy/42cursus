/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:45:09 by marvin            #+#    #+#             */
/*   Updated: 2023/07/05 11:12:03 by vpoirot          ###   ########.fr       */
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
		current = timestamp() - begin;
}

void	*ft_routine(void *arg)
{
	t_info	*s_info;

	s_info = (t_info *)arg;
	if (s_info->rank % 2 == 0)
		ft_usleep(100);
	take_fork(s_info);
	sleeping(s_info);
	return (NULL);
}
