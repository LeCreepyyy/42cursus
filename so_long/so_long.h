/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:01:04 by vpoirot           #+#    #+#             */
/*   Updated: 2023/05/02 13:44:14 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"
# include "./MLX42/include/MLX42/MLX42.h"

typedef struct ft_mlx
{
	mlx_image_t	*img[6];
	mlx_t		*mlx;
	int			*player_p;
	int			moov;
	char		**map;
	int			width;
	int			height;
}	t_ft_mlx;

// function for map

char	**set_map_tab(char *map);
char	*ft_strjoin_n(char *dst, char *src);
int		check_map(char **map, t_ft_mlx	*ft_mlx);
int		verif_valid(char **map, int e, int p);
int		count_item(char **map);
int		*position_p(char **map);
int		check_border(char **map);

// create map

void	display_map(t_ft_mlx *ft_mlx, int x, int y);
char	**dup_map(char **map);

// function utils

int		len_tab(char **map);
int		ft_action(t_ft_mlx *ft_mlx, int y, int x);
void	free_return_error(t_ft_mlx *ft_mlx);

#endif