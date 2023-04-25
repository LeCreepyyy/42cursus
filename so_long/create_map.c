/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:36:01 by vpoirot           #+#    #+#             */
/*   Updated: 2023/04/25 15:24:23 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_case(char c, t_ft_mlx *ft_mlx)
{
	if (c == '1')
	{
		ft_mlx->img = mlx_texture_to_image(ft_mlx->mlx,
				mlx_load_png("assets/wall.png"));
		mlx_image_to_window(ft_mlx->mlx, ft_mlx->img,
			(c) * 48, (c) * 48);
	}
	/*if (c == '0')
	if (c == 'C')
	if (c == 'E')
	if (c == 'P')*/
}

void	display_map(t_ft_mlx *ft_mlx, int x, int y)
{
	while (ft_mlx->map[y][x])
	{
		x = 0;
		while (ft_mlx->map[y][x])
		{
			display_case(ft_mlx->map[y][x], ft_mlx);
			x++;
		}
		y++;
	}
}
