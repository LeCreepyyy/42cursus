/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:30:04 by vpoirot           #+#    #+#             */
/*   Updated: 2022/12/19 15:18:09 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	ft_putpoint(unsigned long p)
{
	int	nb;

	nb = 0;
	if (p >= 16)
	{
		nb += ft_putpoint(p / 16);
		nb += ft_putpoint(p % 16);
	}
	if (p < 16)
	{
		if (p < 10)
			nb += ft_putchar(p + 48);
		else
			nb += ft_putchar(p + 87);
	}
	return (nb);
}
