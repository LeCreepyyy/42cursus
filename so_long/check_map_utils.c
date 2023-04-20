/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:21:09 by vpoirot           #+#    #+#             */
/*   Updated: 2023/04/20 13:53:33 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_valid(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] != '1' && map[x][y] != '0'
				&& map[x][y] != 'C' && map[x][y] != 'P'
				&& map[x][y] != 'E' && map[x][y] != '\n')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

int	count_item(char **map)
{
	int	c;
	int	x;
	int	y;

	c = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				c++;
			x++;
		}
		y++;
	}
	return (c);
}

int	*position_p(char **map)
{
	int	x;
	int	y;
	int	*player;

	y = 0;
	x = 0;
	player = malloc(2 * sizeof(int));
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
			{
				player[0] = x;
				player[1] = y;
				return (player);
			}
			y++;
		}
		x++;
	}
	return (0);
}

char	**res_map(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == '6')
				map[x][y] = '0';
			y++;
		}
		x++;
	}
	return (map);
}

int	check_border(char **map)
{
	int	x;
	int	y;

	x = 1;
	y = 0;
	while (map[0][y])
	{
		if (map[0][y] != '1' || map[len_tab(map) - 1][y] != '1')
			return (1);
		y++;
	}
	y = 0;
	while (map[x] != map[len_tab(map) - 1])
	{
		if (map[x][0] != '1' || map[x][ft_strlen(map[0]) - 1] != '1')
			return (1);
		x++;
	}
	return (0);
}
