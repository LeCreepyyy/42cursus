/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:22:20 by vpoirot           #+#    #+#             */
/*   Updated: 2022/12/20 13:46:11 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

int				ft_printf(const char *str, ...);
int				ft_puthexa(unsigned int i, int nb, char X);
int				ft_puthexa_up(unsigned int i, int nb);
unsigned long	ft_putpoint(unsigned long p);
int				ft_putcharnb(char c, int nb);

#endif
