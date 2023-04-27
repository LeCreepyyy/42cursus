/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:36:01 by vpoirot           #+#    #+#             */
/*   Updated: 2023/04/27 11:00:55 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_case(char c, t_ft_mlx *ft_mlx, int x, int y)
{
	ft_mlx->img = mlx_texture_to_image(ft_mlx->mlx,
			mlx_load_png("assets/floor.png"));
	mlx_image_to_window(ft_mlx->mlx, ft_mlx->img,
		x * 48, y * 48);
	if (c == '1')
	{
		ft_mlx->img = mlx_texture_to_image(ft_mlx->mlx,
				mlx_load_png("assets/wall.png"));
		mlx_image_to_window(ft_mlx->mlx, ft_mlx->img,
			x * 48, y * 48);
	}
	if (c == 'C')
	{
		ft_mlx->img = mlx_texture_to_image(ft_mlx->mlx,
				mlx_load_png("assets/banana.png"));
		mlx_image_to_window(ft_mlx->mlx, ft_mlx->img,
			x * 48, y * 48);
	}
	if (c == 'E')
	{
		ft_mlx->img = mlx_texture_to_image(ft_mlx->mlx,
				mlx_load_png("assets/baril.png"));
		mlx_image_to_window(ft_mlx->mlx, ft_mlx->img,
			x * 48, y * 48);
	}
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
}
