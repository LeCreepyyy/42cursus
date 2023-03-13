/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_sentence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:43:37 by vpoirot           #+#    #+#             */
/*   Updated: 2023/01/25 09:53:42 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*rev_sent(char *str)
{
	int		i;
	int		a;
	char	*stock;

	i = strlen(str);
	while (str[i])
	{
		if (str[i])
			i--;
		else
		{
			a = 0;
			if (stock != 0)
				free(stock);
			stock = malloc(sizeof(char));
			while (stock[a] != 0)
			{
				stock[a] == str[i];
				a++;
				i--;
			}
		}
	}
}

int	main(void)
{
	printf("%s\n", rev_sent("cette phrase vas resortir a l'envers."));
	return (0);
}
