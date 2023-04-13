/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:05:38 by vpoirot           #+#    #+#             */
/*   Updated: 2023/04/13 13:39:59 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	static int	moov = 0;
	t_img		*img_mlx;

	img_mlx = (t_img *)param;
	if (keydata.key == MLX_KEY_ESCAPE
		&& ft_printf("Moov : %d\n", moov / 2))
		mlx_close_window(img_mlx->mlx);
	if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		&& keydata.action == MLX_PRESS)
		img_mlx->img->instances[0].y -= 128;
	if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		&& keydata.action == MLX_PRESS)
		img_mlx->img->instances[0].y += 128;
	if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
		&& keydata.action == MLX_PRESS)
		img_mlx->img->instances[0].x -= 128;
	if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
		&& keydata.action == MLX_PRESS)
		img_mlx->img->instances[0].x += 128;
	moov++;
}

/*
void	ft_map()
{
	int		fd;
	char	*line;

	fd = open("map.txt", O_RDONLY);
	line = get_next_line(fd);
}
*/

int	main(void)
{
	t_img	*im;

	im = malloc(sizeof(t_img));
	im->mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	im->img = mlx_texture_to_image(im->mlx, mlx_load_png("monkey2.png"));
	mlx_image_to_window(im->mlx, im->img, 1024, 600);
	mlx_key_hook(im->mlx, &ft_hook, im);
	mlx_loop(im->mlx);
	mlx_terminate(im->mlx);
	return (0);
}
