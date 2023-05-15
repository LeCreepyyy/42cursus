/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:08:22 by vpoirot           #+#    #+#             */
/*   Updated: 2023/05/15 10:34:52 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin_n(char *dst, char *src)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!src)
		return (free(dst), NULL);
	if (!dst)
		return (free(src), src);
	str = malloc(((ft_strlen(dst) + ft_strlen(src)) + 1) * sizeof(char));
	if (!str)
		return (free(dst), free(src), NULL);
	if (dst)
	{
		while (dst[i])
		{
			str[i] = dst[i];
			i++;
		}
	}
	while (src[j])
		str[i++] = src[j++];
	str[i] = 0;
	return (free(dst), str);
}

int	len_tab(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

char	**dup_map(char **map)
{
	int		y;
	char	**new;

	new = malloc((len_tab(map) + 1) * sizeof(char *));
	if (!new)
		return (0);
	new[len_tab(map)] = 0;
	y = 0;
	while (map[y])
	{
		new[y] = ft_strdup(map[y]);
		y++;
	}
	return (new);
}

void	ft_collect(t_ft_mlx *ft_mlx)
{
	int				i;
	int				j;
	mlx_texture_t	*texture;

	i = 0;
	texture = mlx_load_png("assets/flower.png");
	mlx_delete_image(ft_mlx->mlx, ft_mlx->img[3]);
	ft_mlx->img[3] = mlx_texture_to_image(ft_mlx->mlx, texture);
	free_png_pixel(texture);
	while (ft_mlx->map[i])
	{
		j = 0;
		while (ft_mlx->map[i][j])
		{
			if (ft_mlx->map[i][j] == 'C')
				mlx_image_to_window(ft_mlx->mlx, ft_mlx->img[3],
					j * 48, i * 48);
			j++;
		}
		i++;
	}
}

int	ft_action(t_ft_mlx *ft_mlx, int y, int x)
{
	char				*str;
	static mlx_image_t	*str_img = 0;

	if (ft_mlx->map[y][x] == '1')
		return (0);
	if (ft_mlx->map[y][x] == 'C')
	{
		ft_mlx->map[y][x] = '0';
		ft_collect(ft_mlx);
	}
	str = ft_strjoin("Move :", ft_itoa(ft_mlx->moov));
	mlx_delete_image(ft_mlx->mlx, str_img);
	str_img = mlx_put_string(ft_mlx->mlx, str, 24, 10);
	ft_printf("Move : %d\r", ft_mlx->moov++);
	if (ft_mlx->map[y][x] == '2' && ft_printf("You loose !\n"))
		mlx_close_window(ft_mlx->mlx);
	else if (ft_mlx->map[y][x] == 'E')
	{
		if ((count_item(ft_mlx->map) - 1) == 0)
		{
			mlx_close_window(ft_mlx->mlx);
			ft_printf("Victory !\nYour time : %ds\n", (int)mlx_get_time());
		}
	}
	return (free(str), 1);
}
