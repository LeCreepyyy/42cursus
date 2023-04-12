/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:05:38 by vpoirot           #+#    #+#             */
/*   Updated: 2023/04/12 16:06:57 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_img	*img_mlx;

	img_mlx = (t_img *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(img_mlx->mlx);
	if (keydata.key == MLX_KEY_UP)
		img_mlx->img->instances[0].y -= 100;
	if (keydata.key == MLX_KEY_DOWN)
		img_mlx->img->instances[0].y += 100;
	if (keydata.key == MLX_KEY_LEFT)
		img_mlx->img->instances[0].x -= 100;
	if (keydata.key == MLX_KEY_RIGHT)
		img_mlx->img->instances[0].x += 100;
}

int	main(void)
{
	t_img	*im;

	im = malloc(sizeof(t_img));
	im->mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	im->img = mlx_texture_to_image(im->mlx, mlx_load_png("charac.png"));
	mlx_image_to_window(im->mlx, im->img, 0, 0);
	mlx_key_hook(im->mlx, &ft_hook, im);
	mlx_loop(im->mlx);
	mlx_terminate(im->mlx);
	return (0);
}
