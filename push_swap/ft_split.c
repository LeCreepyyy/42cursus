/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:26:26 by marvin            #+#    #+#             */
/*   Updated: 2023/05/26 19:26:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_cntsplit(char const *str, char car)
{
	size_t	i;
	size_t	split;

	i = 0;
	split = 0;
	while (*str == car && *str)
	{
		str++;
		i++;
	}
	while (*str != 0)
	{
		if (*str == car)
			split++;
		while (*str == car && *str)
			str++;
		if (*str)
			str++;
		i++;
	}
	if (i > 0 && *(str - 1) == car)
		split--;
	return (split + 1);
}

static int	ft_cntcar(char const *str, char car)
{
	size_t	c;

	c = 0;
	while (*str)
	{
		if (*str == car)
			return (c);
		c++;
		str++;
	}
	return (c);
}

static void	**ft_free(void **tab, size_t a)
{
	while (a-- > 0)
		free(tab[a]);
	free(tab);
	return (0);
}

char	**ft_split2(char const *str, char car, char **tab, size_t i)
{
	size_t	a;
	size_t	split;

	a = 0;
	split = 0;
	while (str[i] && split != (size_t)ft_cntsplit(str, car))
	{
		tab[a] = malloc(sizeof(char) * (ft_cntcar(&str[i], car) + 1));
		if (tab[a] == 0)
			return ((char **)ft_free((void **)tab, a));
		ft_strlcpy((char *)tab[a], &str[i], ft_cntcar(&str[i], car) + 1);
		a++;
		i += ft_cntcar(&str[i], car);
		split++;
		while (str[i] == car && str[i])
			i++;
	}
	tab[a] = 0;
	return (tab);
}

char	**ft_split(char *str, char car)
{
	size_t	i;
	char	**tab;

	if (!str)
		return (0);
	if (!str[0])
	{
		tab = malloc(sizeof(char *));
		if (tab == 0)
			return (0);
		tab[0] = 0;
		return (tab);
	}
	i = 0;
	while (str[i] == car && str[i])
		i++;
	tab = malloc(sizeof(char *) * (ft_cntsplit(str, car) + 1));
	if (tab == 0)
		return (0);
	if ((int)i == ft_strlen(str))
	{
		tab[0] = 0;
		return (tab);
	}
	return (ft_split2(str, car, tab, i));
}