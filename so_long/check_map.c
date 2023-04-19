/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:49:42 by vpoirot           #+#    #+#             */
/*   Updated: 2023/04/19 15:10:37 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_possible(char **map, int x, int y, t_ft_mlx	*ft_mlx)
{
	if (map[x][y] == 'X')
		return (0);
	if (map[x][y + 1] == '0' || map[x][y + 1] == 'C')
	{
		map[x][y] = '6';
		y++;
		is_possible(map, x, y, ft_mlx);
	}
	if (map[x][y - 1] == '0' || map[x][y - 1] == 'C')
	{
		map[x][y] = '6';
		y--;
		is_possible(map, x, y, ft_mlx);
	}
	if (map[x + 1][y] == '0' || map[x + 1][y] == 'C')
	{
		map[x][y] = '6';
		x++;
		is_possible(map, x, y, ft_mlx);
	}
	if (map[x - 1][y] == '0' || map[x - 1][y] == 'C')
	{
		map[x][y] = '6';
		x--;
		is_possible(map, x, y, ft_mlx);
	}
	if (count_item(map) == 0 && map[x][y] == 'E')
		return (1);
	else
	{
		if (map[x][y] == 'E')
			map[x][y] = 'X';
		is_possible(res_map(map), ft_mlx->player_p[0], ft_mlx->player_p[1], ft_mlx);
	}
	return (0);
}

int	check_map(char **map, t_ft_mlx	*ft_mlx)
{
	int	*temp;

	if (verif_valid(map) == 1)
	{
		ft_printf("Map contain other that (1 0 C E P)");
		return (0);
	}
	temp = position_p(map);
	ft_mlx->player_p = position_p(map);
	if (is_possible(map, temp[0], temp[1], ft_mlx) == 1)
		return (1);
	return (0);
}

/*
		y
  ______________
  |1111111111111
  |1001666666661
x |1006611111661
  |166611E0006X1
  |1111111111111
*/
