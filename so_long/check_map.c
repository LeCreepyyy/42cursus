/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:49:42 by vpoirot           #+#    #+#             */
/*   Updated: 2023/04/18 15:29:49 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_valid(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' || map[y][x] != '0'
				|| map[x][y] != 'C' || map[x][y] != 'P'
				|| map[x][y] != 'E')
				return (1);
			x++;
		}
		y++;
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
			if (map[y][x] == 'C')
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

int	is_possible(char **map, int c, int x, int y)
{
	return (0);
}

int	check_map(char **map)
{
	int	c;
	int	*temp;

	if (verif_valid(map) == 1)
		return (0);
	c = count_item(map);
	temp = position_p(map);
	if (is_possible(map, c, temp[0], temp[1]) == 1)
		return (0);
	return (0);
}

/*
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
*/
