/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:49:42 by vpoirot           #+#    #+#             */
/*   Updated: 2023/04/21 10:44:48 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_case(char **map)
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

void	size_d(int *dx, int *dy)
{
	*dx = 0;
	*(dx + 1) = 1;
	*(dx + 2) = 0;
	*(dx + 3) = -1;
	*dy = -1;
	*(dy + 1) = 0;
	*(dy + 2) = 1;
	*(dy + 3) = 0;
}

int	is_possible(char **map, int x, int y, t_ft_mlx *ft_mlx)
{
	int	*dx;
	int	*dy;
	int	i;
	int	new_x;
	int	new_y;

	i = -1;
	dx = malloc(4 * sizeof(int));
	dy = malloc(4 * sizeof(int));
	size_d(dx, dy);
	if (count_item(map) == 0 || check_case(map))
		return (free(dx), free(dy), 1);
	while (++i < 4)
	{
		new_x = x + dx[i];
		new_y = y + dy[i];
		if (map[new_x][new_y] != '1' && map[new_x][new_y] != '6')
		{
			map[new_x][new_y] = '6';
			if (is_possible(map, new_x, new_y, ft_mlx))
				return (free(dx), free(dy), 1);
			map[new_x][new_y] = '0';
		}
	}
	return (free(dx), free(dy), 0);
}

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
	ft_mlx->player_p = position_p(map);
	if (is_possible(map, temp[0], temp[1], ft_mlx) == 0)
	{
		ft_printf("Error\nMap is not possible  !\n");
		return (0);
	}
	return (1);
}
