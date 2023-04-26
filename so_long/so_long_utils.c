/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:08:22 by vpoirot           #+#    #+#             */
/*   Updated: 2023/04/26 15:26:38 by vpoirot          ###   ########.fr       */
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

int	ft_action(t_ft_mlx *ft_mlx, int y, int x)
{
	if (ft_mlx->map[y][x] == '1')
		return (0);
	ft_printf("Move : %d\r", ft_mlx->moov++);
	return (1);
}
