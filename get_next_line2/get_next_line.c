/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:51:04 by vpoirot           #+#    #+#             */
/*   Updated: 2023/03/20 15:33:30 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	findstop(char *stock)
{
	size_t	i;

	i = 0;
	while (stock[i])
	{
		if (stock[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*setline(char *line, char *stock)
{
	size_t	i;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	line = calloc(i + 2, sizeof(char));
	i = 0;
	while (stock[i] && stock[i] != '\n')
	{
		line[i] = stock[i];
		i++;
	}
	if (stock[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*setstock(char *stock)
{
	size_t	j;
	int		t;
	char	*stash;

	j = 0;
	while (stock[j] != '\n' && stock[j])
		j++;
	if (j == len_str(stock))
		return (stock);
	t = 0;
	stash = malloc(((len_str(stock) - j) + 1) * sizeof(char));
	if (stash == 0)
		return (0);
	while (stock[j++] != '\0')
		stash[t++] = stock[j];
	free(stock);
	return (stash);
}

char	*read_buffer(int fd, char *stock)
{
	int		i;
	char	*buffer;

	if (!stock)
		stock = ft_calloc(1, sizeof(char));
	i = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (0);
		}
		stock = ft_strjoin(stock, buffer);
		if (findstop(stock) == 1)
			break ;
	}
	free (buffer);
	return (stock);
}

char	*get_next_line(int fd)
{
	// init var & verif error
	char		line;
	static char	stock;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	// read & set buffer
	stock = read_buffer(stock, fd);
	if (!stock)
		return (0);
	// init & set line
	line = 0;
	line = setline(line, stock);
	// set stock & return
	stock = setstock(stock);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
		printf("%s", line);
	printf("%s", line);
}
