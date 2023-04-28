/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:22:20 by vpoirot           #+#    #+#             */
/*   Updated: 2023/04/28 10:22:20 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	ft_prset(va_list arglst, int index, const char *str, ...)
{
	index++;
	if (str[index] == 37)
		return (ft_putcharnb('%', 0));
	else if (str[index] == 'c')
		return (ft_putcharnb(va_arg(arglst, int), 0));
	else if (str[index] == 's')
		return (ft_putstr(va_arg(arglst, char *), 0));
	else if (str[index] == 'i' || str[index] == 'd')
		return (ft_itoas(va_arg(arglst, int)));
	else if (str[index] == 'u')
		return (ft_itoa_uns(va_arg(arglst, unsigned int)));
	else if (str[index] == 'x')
		return (ft_puthexa(va_arg(arglst, int), 0, 'x'));
	else if (str[index] == 'X')
		return (ft_puthexa(va_arg(arglst, int), 0, 'X'));
	else if (str[index] == 'p')
	{
		if (ft_putstr("0x", 0) == -1)
			return (-1);
		return (ft_putpoint(va_arg(arglst, unsigned long)) + 2);
	}
	return (-1);
}

static int	ft_printf2(const char *str, int index, int nb, va_list	arglst)
{
	int	t;

	while (str[index] != 0)
	{
		if (str[index] == 37)
		{
			t = ft_prset(arglst, index, str);
			if (t == -1)
				return (-1);
			nb += t;
			index++;
		}
		else
		{
			if (ft_putchar(str[index]) == -1)
				return (-1);
			nb++;
		}
		index++;
	}
	return (nb);
}

int	ft_printf(const char *str, ...)
{
	int		nb;
	int		index;
	va_list	arglst;

	nb = 0;
	index = 0;
	va_start(arglst, str);
	return (ft_printf2(str, index, nb, arglst));
}
/*
int	main(void)
{
	printf("-----\n");
	printf("La vrai fonction : |%d|\n", printf("%u\n", -10));
	printf("-----\n");
	printf("ma fonction : |%d|\n", ft_printf("%u\n", -10));
	printf("-----\n");
	return (0);
}*/
