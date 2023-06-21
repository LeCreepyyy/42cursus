/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:09:06 by vpoirot           #+#    #+#             */
/*   Updated: 2023/06/21 13:05:08 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

# define YELLOW	"\e[33m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"

typedef struct s_info {
	int			rank;
	pthread_t	thread;
}	t_info;

typedef struct s_philo {
	int				number;
	int				death_time;
	int				eat;
	int				sleep;
	int				limit;
	int				died;
	int				*fork;
	t_info			*s_info;
	pthread_mutex_t	*m_fork;
}	t_philo;

//fonction
void	start_routine(t_philo *s_philo);
void	take_fork(t_philo *s_philo);
void	*ft_routine(void *arg);

//utils
int		ft_strlen(char *str);
int		ft_atoi(const char *nptr);
char	*ft_itoa(int nb);
int		exit_error(t_philo *stc, char **argv, char *err);
void	ft_free(t_philo *s_philo);

#endif
