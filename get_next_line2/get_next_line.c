/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:51:04 by vpoirot           #+#    #+#             */
/*   Updated: 2023/03/23 13:56:47 by vpoirot          ###   ########.fr       */
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
	if (stock[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
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
	t = 0;
	stash = ft_calloc((len_str(stock) - j) + 1, sizeof(char));
	if (!stash)
	{
		free(stock);
		return (0);
	}
	while (stock[j++] != '\0')
		stash[t++] = stock[j];
	free(stock);
	return (stash);
}

char	*read_buffer(char *stock, int fd, int i)
{
	char	*buffer;

	if (!stock)
	{
		stock = ft_calloc(1, sizeof(char));
		if (!stock)
			return (0);
	}
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (0);
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[i] = 0;
		stock = ft_strjoin(stock, buffer);
		if (findstop(stock) == 1)
			break ;
	}
	free (buffer);
	return (stock);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stock[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		free(stock[fd]);
		stock[fd] = 0;
		return (0);
	}
	stock[fd] = read_buffer(stock[fd], fd, 1);
	if (!stock[fd] || stock[fd][0] == '\0')
	{
		free(stock[fd]);
		stock[fd] = 0;
		return (0);
	}
	line = 0;
	line = setline(line, stock[fd]);
	stock[fd] = setstock(stock[fd]);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("read_error.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
		printf("%s", line);
	printf("%s", line);
}
*/