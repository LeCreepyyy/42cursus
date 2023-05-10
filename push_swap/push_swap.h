/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:03:06 by vpoirot           #+#    #+#             */
/*   Updated: 2023/05/10 10:48:08 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

// ~Instructions~
void	swap(int *stack);
void	reverse(int *tab);
void	push(int *dest, int *stack);

// ~For arguments~
int		check_arg(char **arg, int count);
int		*create_a(int argc, char **argv);
int		*create_b(int argc);

// ~Function utils~
void	ft_putstr_fd(char *str, int fd);
int		ft_strlen(char *str);
long	ft_atoi(char *nb);
int		lenstack(int *tab);

#endif
