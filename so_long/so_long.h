/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:01:04 by vpoirot           #+#    #+#             */
/*   Updated: 2023/04/12 15:59:17 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "./MLX42/include/MLX42/MLX42.h"

typedef struct img_mlx
{
	mlx_image_t	*img;
	mlx_t		*mlx;
}	t_img;

# define WIDTH 1080
# define HEIGHT 920

#endif