/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:09:06 by vpoirot           #+#    #+#             */
/*   Updated: 2023/07/05 11:16:55 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define GRAY	"\e[30m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PINK	"\e[35m"
# define SKY	"\e[36m"
# define WHITE	"\e[37m"

typedef struct s_info {
	int				rank;
	pthread_t		thread;
	struct s_philo	*s_data;
}	t_info;

typedef struct s_philo {
	int				number;
	int				death_time;
	int				eat;
	int				sleep;
	int				limit;
	int				died;
	int				*fork;
	int				beginning;
	t_info			*s_info;
	pthread_mutex_t	*m_fork;
	pthread_mutex_t	m_print;
}	t_philo;

//fonction
void	start_routine(t_philo *s_philo);
void	take_fork(t_info *s_info);
void	*ft_routine(void *arg);
void	sleeping(t_info *s_info);

//utils
int		ft_strlen(char *str);
int		ft_atoi(const char *nptr);
int		exit_error(t_philo *stc, char **argv, char *err);
void	ft_free(t_philo *s_philo);
int		timestamp(void);
void	mutex_print(char *message, int n_philo, t_philo *s_philo, char *color);
void	ft_usleep(int time);

#endif
