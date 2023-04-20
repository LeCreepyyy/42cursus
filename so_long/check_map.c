/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:49:42 by vpoirot           #+#    #+#             */
/*   Updated: 2023/04/20 14:53:26 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
