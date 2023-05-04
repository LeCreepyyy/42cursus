/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 09:50:31 by vpoirot           #+#    #+#             */
/*   Updated: 2023/05/04 09:58:57 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function for count line of tab (for malloc of tab)
int	len_n(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			n++;
		i++;
	}
	n++;
	return (n);
}

// function for count size (\n or \0 is char of end)
int	ft_strlen_n(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

// function for set line of map into the tab
char	*strdup_n(char *dst, char *src)
{
	int			j;
	static int	i = 0;

	j = 0;
	while (src[i] && src[i] != '\n')
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = 0;
	if (src[i] == '\n')
		i++;
	return (dst);
}

// function for set map into the tab
char	**set_map_tab(char *map)
{
	char	**tab;
	int		i;
	int		len_x;

	i = 0;
	tab = malloc((len_n(map) + 1) * sizeof(char *));
	if (!tab)
		return (0);
	tab[len_n(map)] = 0;
	len_x = ft_strlen_n(map);
	while (i < len_n(map))
	{
		tab[i] = malloc((len_x + 1) * sizeof(char));
		if (!tab[i])
			free_tab(tab);
		if (!tab[i])
			return (0);
		strdup_n(tab[i], map);
		i++;
	}
	return (tab);
}
