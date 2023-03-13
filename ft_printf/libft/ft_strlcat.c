/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:40:33 by vpoirot           #+#    #+#             */
/*   Updated: 2022/11/23 15:56:45 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	h;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	h = 0;
	src_len = ft_strlen(src);
	dst_len = 0;
	if (len == 0 || (dst == NULL && src == NULL))
		return (src_len + len);
	while (dst[i++])
		dst_len++;
	i = dst_len;
	if (dst_len < len - 1 && len > 0)
	{
		while (src[h] && dst_len + h < len - 1)
			dst[i++] = src[h++];
		dst[i] = 0;
	}
	if (dst_len > len)
		dst_len = len;
	return (dst_len + src_len);
}
