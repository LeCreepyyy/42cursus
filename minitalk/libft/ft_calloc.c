/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:03:37 by vpoirot           #+#    #+#             */
/*   Updated: 2022/11/16 10:57:03 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*table;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	table = malloc(nmemb * size);
	if (!table)
		return (0);
	ft_bzero(table, nmemb * size);
	return (table);
}
