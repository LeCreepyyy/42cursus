/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:29:50 by vpoirot           #+#    #+#             */
/*   Updated: 2022/11/22 15:08:49 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strdup(const char *s)
{
	char	*dst;

	dst = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dst == 0)
		return (0);
	return (ft_memcpy(dst, s, ft_strlen(s) + 1));
}
