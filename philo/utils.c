/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:34:01 by vpoirot           #+#    #+#             */
/*   Updated: 2023/07/20 13:54:44 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	int			mult;
	long		nb;

	mult = 1;
	nb = 0;
	i = 0;
	if (nptr[i] == '-' && nptr[i + 1] >= '0' && nptr[i + 1] <= '9')
		mult = -1;
	if (!(nptr[i] == '+' || nptr[i] == '-'))
		if (!(nptr[i] >= '0' && nptr[i] <= '9'))
			return (0);
	if (nptr[i] >= '0' && nptr[i] <= '9')
		i--;
	i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		nb = (nb * 10) + (nptr[i++] - '0');
	if (nb > INT_MAX || nb < INT_MIN)
		return (-2);
	nb *= mult;
	return (nb);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1[i] != s2[i])
		return (s1[i] - s2[i]);
	return (0);
}

int	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	mutex_print(char *message, int n_philo, t_philo *s_philo, char *color)
{
	pthread_mutex_lock(&s_philo->m_death);
	if (s_philo->died != 0)
	{
		pthread_mutex_unlock(&s_philo->m_death);
		return ;
	}
	pthread_mutex_unlock(&s_philo->m_death);
	pthread_mutex_lock(&s_philo->m_print);
	if (color == NULL)
		color = "\e[0m";
	printf("%s%d %d %s\n", color, (timestamp() - s_philo->beginning),
		n_philo, message);
	pthread_mutex_unlock(&s_philo->m_print);
}
