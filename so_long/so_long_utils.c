/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:08:22 by vpoirot           #+#    #+#             */
/*   Updated: 2023/04/17 14:34:34 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
	{
		free(tab[i]);
		i++;
	}
}

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

void	print_map(char	**tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
}
