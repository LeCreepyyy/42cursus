/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:45:09 by marvin            #+#    #+#             */
/*   Updated: 2023/07/04 14:36:24 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *arg)
{
	t_info	*s_info;

	s_info = (t_info *)arg;
	if (s_info->rank % 2 == 0)
		usleep(100);
	take_fork(s_info);
	return (NULL);
}
