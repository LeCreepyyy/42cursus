/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 09:50:31 by vpoirot           #+#    #+#             */
/*   Updated: 2023/04/14 15:02:20 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	return (i);
}

char	**set_map_tab(char *map)
{
	char	**tab;
	int		i;

	i = 0;
	tab = malloc((len_n(map) + 1) * sizeof(char *));
	if (!tab)
		return (0);
	while (map[i])
	{
		i++;
	}
	return (tab);
}
