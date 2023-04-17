/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:01:04 by vpoirot           #+#    #+#             */
/*   Updated: 2023/04/17 13:27:04 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"
# include "./MLX42/include/MLX42/MLX42.h"

typedef struct ft_mlx
{
	mlx_image_t	*img;
	mlx_t		*mlx;
	mlx_t		*width;
	mlx_t		*height;
	int			moov;
}	t_ft_mlx;

// function for map

char	**set_map_tab(char *map);
char	*ft_strjoin_n(char *dst, char *src);
void	print_map(char	**tab);


// function utils

void	free_tab(char **tab);

#endif