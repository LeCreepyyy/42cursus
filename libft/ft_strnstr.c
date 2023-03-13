/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:01:53 by vpoirot           #+#    #+#             */
/*   Updated: 2022/12/01 11:36:06 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;

	if (len == 0 && (big == 0 || little == 0))
		return (0);
	len_little = ft_strlen((char *)little);
	if (len_little > (unsigned long)ft_strlen((char *)big) || len_little > len)
		return (0);
	if (little == big)
		return ((char *)big);
	if (*little == 0)
		return ((char *)big);
	len -= (len_little - 1);
	while (len-- && *big)
	{
		if (*big == *little)
		{
			if (!ft_strncmp((char *)big, (char *)little,
					len_little))
				return ((char *)big);
		}
		big++;
	}
	return (0);
}
