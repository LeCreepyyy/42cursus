/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:41:06 by vpoirot           #+#    #+#             */
/*   Updated: 2022/12/20 13:46:02 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int i, int nb, char X)
{
	char	*str;
	int		n;

	str = "0123456789abcdef";
	if (X == 'X')
		str = "0123456789ABCDEF";
	n = 0;
	if (i < 16)
		return (ft_putchar(str[i]));
	else
	{
		n = ft_puthexa(i / 16, nb / 2, X);
		if (n == -1)
			return (-1);
		nb += n;
		n = ft_puthexa(i % 16, nb / 2, X);
		if (n == -1)
			return (-1);
		nb += n;
	}
	return (nb);
}
