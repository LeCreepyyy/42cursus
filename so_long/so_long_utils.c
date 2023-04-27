/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:08:22 by vpoirot           #+#    #+#             */
/*   Updated: 2023/04/27 13:58:23 by vpoirot          ###   ########.fr       */
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
	if (dst)
		str = malloc(((ft_strlen(dst) + ft_strlen(src)) + 1) * sizeof(char));
	else
		str = malloc((ft_strlen(src) + 1) * sizeof(char));
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
	return (str);
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

void	print_map(char	**map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			ft_printf("%c", map[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}

int	ft_action(t_ft_mlx *ft_mlx, int y, int x)
{
	if (ft_mlx->map[y][x] == '1')
		return (0);
	if (ft_mlx->map[y][x] == 'C')
		ft_mlx->map[y][x] = '0';
	if (ft_mlx->map[y][x] == 'E')
	{
		if ((count_item(ft_mlx->map) - 1) == 0)
			mlx_close_window(ft_mlx->mlx);
	}
	ft_printf("Move : %d\r", ft_mlx->moov++);
	return (1);
}
