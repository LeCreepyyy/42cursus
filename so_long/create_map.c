/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:36:01 by vpoirot           #+#    #+#             */
/*   Updated: 2023/05/02 10:36:47 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_case(char c, t_ft_mlx *ft_mlx, int x, int y)
{
	mlx_image_to_window(ft_mlx->mlx, ft_mlx->img[0], x * 48, y * 48);
	if (c == '1')
		mlx_image_to_window(ft_mlx->mlx, ft_mlx->img[2], x * 48, y * 48);
	if (c == 'C')
		mlx_image_to_window(ft_mlx->mlx, ft_mlx->img[3], x * 48, y * 48);
	if (c == 'E')
		mlx_image_to_window(ft_mlx->mlx, ft_mlx->img[4], x * 48, y * 48);
	if (c == '2')
		mlx_image_to_window(ft_mlx->mlx, ft_mlx->img[5], x * 48, y * 48);
}

void	display_map(t_ft_mlx *ft_mlx, int x, int y)
{
	while (ft_mlx->map[y])
	{
		x = 0;
		while (ft_mlx->map[y][x])
		{
			display_case(ft_mlx->map[y][x], ft_mlx, x, y);
			x++;
		}
		y++;
	}
	mlx_image_to_window(ft_mlx->mlx, ft_mlx->img[1],
		ft_mlx->player_p[1] * 48, ft_mlx->player_p[0] * 48);
}
