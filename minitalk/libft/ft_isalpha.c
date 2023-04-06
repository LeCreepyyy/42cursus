/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:39:54 by vpoirot           #+#    #+#             */
/*   Updated: 2023/04/06 12:29:23 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int w)
{
	if ((w >= 'a' && w <= 'z')
		|| (w >= 'A' && w <= 'Z'))
		return (1);
	else
		return (0);
}
