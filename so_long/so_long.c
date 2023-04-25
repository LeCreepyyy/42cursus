/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:05:38 by vpoirot           #+#    #+#             */
/*   Updated: 2023/04/25 15:25:50 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_ft_mlx	*ft_mlx;

	ft_mlx = (t_ft_mlx *)param;
	if (keydata.key == MLX_KEY_ESCAPE
		&& ft_printf("C'est raté mon grand !\n"))
		mlx_close_window(ft_mlx->mlx);
	if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		&& keydata.action == MLX_PRESS
		&& ft_printf("Move : %d\r", ft_mlx->moov++))
		ft_mlx->img->instances[0].y -= 48;
	if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		&& keydata.action == MLX_PRESS
		&& ft_printf("Move : %d\r", ft_mlx->moov++))
		ft_mlx->img->instances[0].y += 48;
	if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
		&& keydata.action == MLX_PRESS
		&& ft_printf("Move : %d\r", ft_mlx->moov++))
		ft_mlx->img->instances[0].x -= 48;
	if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
		&& keydata.action == MLX_PRESS
		&& ft_printf("Move : %d\r", ft_mlx->moov++))
		ft_mlx->img->instances[0].x += 48;
}

char	**ft_map(char **tab)
{
	int		fd;
	char	*map;
	char	*temp;

	fd = open("map.txt", O_RDONLY);
	temp = 0;
	while (!temp || temp[ft_strlen(temp) - 1] == '\n')
	{
		temp = get_next_line(fd);
		map = ft_strjoin_n(map, temp);
	}
	tab = set_map_tab(map);
	return (tab);
}

void	ft_window(t_ft_mlx *ft_mlx)
{
	ft_mlx->height = (len_tab(ft_mlx->map) * 48);
	ft_mlx->width = (ft_strlen(ft_mlx->map[0]) * 48);
	ft_mlx->mlx = mlx_init(ft_mlx->width, ft_mlx->height, "so_long", true);
	display_map(ft_mlx, 0, 0);
}

int	main(void)
{
	char		**tab;
	t_ft_mlx	*ft_mlx;

	ft_mlx = malloc(sizeof(t_ft_mlx));
	if (!ft_mlx)
		return (0);
	tab = 0;
	tab = ft_map(tab);
	if (check_map(tab, ft_mlx) == 0)
		return (0);
	ft_mlx->moov = 1;
	ft_mlx->map = tab;
	ft_window(ft_mlx);
	ft_mlx->img = mlx_texture_to_image(ft_mlx->mlx,
			mlx_load_png("assets/monkey.png"));
	mlx_image_to_window(ft_mlx->mlx, ft_mlx->img,
		(ft_mlx->player_p[1]) * 48, (ft_mlx->player_p[0]) * 48);
	mlx_key_hook(ft_mlx->mlx, &ft_hook, ft_mlx);
	mlx_loop(ft_mlx->mlx);
	mlx_terminate(ft_mlx->mlx);
	free(ft_mlx);
	return (0);
}
