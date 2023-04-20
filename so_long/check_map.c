/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:49:42 by vpoirot           #+#    #+#             */
/*   Updated: 2023/04/20 15:36:18 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
int	is_possible(char **map, int x, int y, t_ft_mlx	*ft_mlx)
{
	if (count_item(map) == 0)
		return (0);
	if (map[x][y + 1] != '1')
	{
		map[x][y] = '6';
		is_possible(map, x, ++y, ft_mlx);
	}
	if (map[x][y - 1] != '1')
	{
		map[x][y] = '6';
		is_possible(map, x, --y, ft_mlx);
	}
	if (map[x + 1][y] != '1')
	{
		map[x][y] = '6';
		is_possible(map, ++x, y, ft_mlx);
	}
	if (map[x - 1][y] != '1')
	{
		map[x][y] = '6';
		is_possible(map, --x, y, ft_mlx);
	}
	return (1);
}
*/

int	toutes_les_cases_ont_ete_visitees(char **map)
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
			if (map[x][y] == '0' || map[x][y] == '2')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	is_possible(char **map, int x, int y, t_ft_mlx *ft_mlx)
{
	if (count_item(map) == 0 || toutes_les_cases_ont_ete_visitees(map))
		return (1);
	int dx[] = {0, 0, 1, -1};
	int dy[] = {1, -1, 0, 0};
	int i = 0;
	while (i < 4)
	{
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		if (map[new_x][new_y] != '1' && map[new_x][new_y] != '6')
		{
			map[new_x][new_y] = '6';
			if (is_possible(map, new_x, new_y, ft_mlx))
				return (1);
			map[new_x][new_y] = '0';
		}
		i++;
	}
	return (0);
}

/*
		y
  ______________
  |1111111111111
  |1C01000000001
x |1000011111001
  |1P0011E000001
  |1111111111111
*/

int	check_map(char **map, t_ft_mlx	*ft_mlx)
{
	int	*temp;

	if (verif_valid(map) == 1 || check_border(map) == 1)
	{
		if (verif_valid(map) == 1)
			ft_printf("Error\nMap contain other that (1 0 C E P)\n");
		else
			ft_printf("Error\nMap border is not good ! (The border is 1)\n");
		return (0);
	}
	temp = position_p(map);
	ft_mlx->player_p = position_p(map);/*
	if (is_possible(map, temp[0], temp[1], ft_mlx) == 1)
	{
		ft_printf("Error\nMap is not possible  !\n");
		return (0);
	}*/
	return (1);
}
