/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:03:06 by vpoirot           #+#    #+#             */
/*   Updated: 2023/05/17 15:25:46 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

// ~Instructions~
void	swap(int *stack, char c);
void	s_swap(int *a, int *b);
void	rotate(int *tab, char c);
void	r_rotate(int *tab, char c);
void	push(int *dest, int *stack, char c);
void	rr(int *a, int *b);
void	rrr(int *a, int *b);

// ~For sort~
void	sort_three(int *a);
void	little_algo(int *a, int *b);
void	get_push(int *a, int *b);
int		get_min(int *stack);
int		get_max(int *stack);
void	big_sort(int *a, int *b);
void	is_two_arg(int *a);
void	r_sort_three(int *a);

// ~For arguments~
int		check_arg(char **arg, int count);
int		*create_a(int argc, char **argv);
int		*create_b(int argc);

// ~Function utils~
void	ft_putstr_fd(char *str, int fd);
int		ft_strlen(char *str);
long	ft_atoi(char *nb);
int		lenstack(int *tab);
int		len_tab(char **tab);

#endif
