/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:24:01 by vpoirot           #+#    #+#             */
/*   Updated: 2022/10/31 15:29:07 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int w)
{
	if ((w >= 'a' && w <= 'z')
		|| (w >= 'A' && w <= 'Z')
		|| (w >= '0' && w <= '9'))
		return (1);
	else
		return (0);
}
