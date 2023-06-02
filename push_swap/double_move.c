/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:26:33 by vpoirot           #+#    #+#             */
/*   Updated: 2023/06/02 15:18:21 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_swap(int *a, int *b)
{
	swap(a, 0);
	swap(b, 0);
	write(1, "ss\n", 3);
}

void	rotate_checker(int *a, int *b)
{
	r(a);
	r(b);
}

void	rrotate_checker(int *a, int *b)
{
	r_r(a);
	r_r(b);
}

void	rr(int *a, int *b)
{
	rotate(a, 0);
	rotate(b, 0);
	write(1, "rr\n", 3);
}

void	rrr(int *a, int *b)
{
	r_rotate(a, 0);
	r_rotate(b, 0);
	write(1, "rrr\n", 4);
}
