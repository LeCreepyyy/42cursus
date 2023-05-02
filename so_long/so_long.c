/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:05:38 by vpoirot           #+#    #+#             */
/*   Updated: 2023/05/02 16:06:39 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_ft_mlx	*ft_mlx;

	ft_mlx = (t_ft_mlx *)param;
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE
		&& ft_printf("Your time : %ds\n", (int)mlx_get_time()))
		mlx_close_window(ft_mlx->mlx);
	if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		&& ft_action(ft_mlx, (ft_mlx->player_p[0] - 1), ft_mlx->player_p[1])
		&& ft_mlx->player_p[0]--)
		ft_mlx->img[1]->instances[0].y -= 48;
	if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		&& ft_action(ft_mlx, (ft_mlx->player_p[0] + 1), ft_mlx->player_p[1])
		&& ft_mlx->player_p[0]++)
		ft_mlx->img[1]->instances[0].y += 48;
	if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
		&& ft_action(ft_mlx, ft_mlx->player_p[0], (ft_mlx->player_p[1] - 1))
		&& ft_mlx->player_p[1]--)
		ft_mlx->img[1]->instances[0].x -= 48;
	if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
		&& ft_action(ft_mlx, ft_mlx->player_p[0], (ft_mlx->player_p[1] + 1))
		&& ft_mlx->player_p[1]++)
		ft_mlx->img[1]->instances[0].x += 48;
}

char	**ft_map(char **tab, char *arg)
{
	int		fd;
	char	*map;
	char	*temp;

	if (ft_strncmp(&arg[ft_strlen(arg) - 4], ".ber", 4) != 0)
		return (0);
	fd = open(arg, O_RDONLY);
	temp = 0;
	map = malloc(sizeof(char));
	if (!map)
		return (0);
	map[0] = 0;
	while (!temp || temp[ft_strlen(temp) - 1] == '\n')
	{
		temp = get_next_line(fd);
		map = ft_strjoin_n(map, temp);
		if (!map)
			return (0);
	}
	tab = set_map_tab(map);
	return (tab);
}

void	ft_window(t_ft_mlx *ft_mlx)
{
	ft_mlx->moov = 1;
	ft_mlx->height = (len_tab(ft_mlx->map) * 48);
	ft_mlx->width = (ft_strlen(ft_mlx->map[0]) * 48);
	ft_mlx->mlx = mlx_init(ft_mlx->width, ft_mlx->height, "so_long", true);
	ft_mlx->img[0] = mlx_texture_to_image(ft_mlx->mlx,
			mlx_load_png("assets/grass.png"));
	ft_mlx->img[1] = mlx_texture_to_image(ft_mlx->mlx,
			mlx_load_png("assets/monkey.png"));
	ft_mlx->img[2] = mlx_texture_to_image(ft_mlx->mlx,
			mlx_load_png("assets/tree.png"));
	ft_mlx->img[3] = mlx_texture_to_image(ft_mlx->mlx,
			mlx_load_png("assets/banana.png"));
	ft_mlx->img[4] = mlx_texture_to_image(ft_mlx->mlx,
			mlx_load_png("assets/baril.png"));
	ft_mlx->img[5] = mlx_texture_to_image(ft_mlx->mlx,
			mlx_load_png("assets/enemy.png"));
	display_map(ft_mlx, 0, 0);
}

int	main(int argc, char **argv)
{
	char		**tab;
	t_ft_mlx	*ft_mlx;

	if (argc != 2)
	{
		ft_printf("Error\n Arg invalid !\n");
		return (0);
	}
	ft_mlx = malloc(sizeof(t_ft_mlx));
	if (!ft_mlx)
		return (0);
	tab = 0;
	ft_mlx->map = ft_map(ft_mlx->map, argv[1]);
	if (!ft_mlx->map)
		return (free_return_error(ft_mlx), 0);
	tab = dup_map(ft_mlx->map);
	if (check_map(tab, ft_mlx) == 0)
		return (0);
	ft_window(ft_mlx);
	mlx_key_hook(ft_mlx->mlx, &ft_hook, ft_mlx);
	mlx_loop(ft_mlx->mlx);
	mlx_terminate(ft_mlx->mlx);
	free_tab(ft_mlx->map);
	ft_printf("Total move : %d\n", (ft_mlx->moov - 1));
	return (free_tab(tab), free(ft_mlx->player_p), free(ft_mlx), 0);
}
