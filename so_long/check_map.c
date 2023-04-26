/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:49:42 by vpoirot           #+#    #+#             */
/*   Updated: 2023/04/26 10:19:21 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_possible(char **map, int y, int x)
{
	map[y][x] = '6';
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C'
		|| map[y + 1][x] == 'E')
		is_possible(map, y + 1, x);
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C'
		|| map[y][x + 1] == 'E')
		is_possible(map, y, x + 1);
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C'
		|| map[y - 1][x] == 'E')
		is_possible(map, y - 1, x);
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C'
		|| map[y][x - 1] == 'E')
		is_possible(map, y, x - 1);
	return ;
}

int	check_map(char **m, t_ft_mlx	*ft_mlx)
{
	int		*temp;

	if (verif_valid(m, 0, 0) == 1 || check_border(m) == 1)
	{
		if (verif_valid(m, 0, 0) == 1)
			ft_printf("Error\nMap contain other that (1 0 C E P)\n");
		else
			ft_printf("Error\nMap border is not good ! (The border is 1)\n");
		return (0);
	}
	temp = position_p(m);
	ft_mlx->player_p = position_p(m);
	if (!ft_mlx->player_p)
	{
		ft_printf("Error\nNo spawn point in map !");
		return (0);
	}
	is_possible(m, ft_mlx->player_p[0], ft_mlx->player_p[1]);
	if (count_item(m) == 0)
		return (1);
	ft_printf("Error\nMap is not possible !");
	return (0);
}
