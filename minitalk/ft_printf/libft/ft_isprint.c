/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:35:33 by vpoirot           #+#    #+#             */
/*   Updated: 2022/11/03 14:39:09 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>
#include "libft.h"

int	ft_isprint(int w)
{
	return (w >= 32 && w <= 126);
}

/*int	main()
{
	int	w;

	w = 25;
	printf("%d\n", ft_isprint(w));
	printf("%d\n", isprint(w));
	return (0);
}*/
