/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:09:06 by vpoirot           #+#    #+#             */
/*   Updated: 2023/06/06 13:52:22 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo {
	int	number;
	int	death;
	int	eat;
	int	sleep;
	int	limit;
	int	fork;
}	t_philo;

//fonction
void	start_routine(t_philo *s_philo);

//utils
int		ft_strlen(char *str);
int		ft_atoi(const char *nptr);
char	*ft_strjoin(char *dst, char *src, int i);

#endif
