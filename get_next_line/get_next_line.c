/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:51:04 by vpoirot           #+#    #+#             */
/*   Updated: 2023/03/14 13:14:50 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	reader_buff(char *buffer, int *i, int fd, int size)
{
	*i = read(fd, buffer, size);
	if (*i <= 0)
	{
		if (*i == -1)
			return (-1);
		return (0);
	}
	buffer[*i] = '\0';
	return (*i);
}

int	findstop(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*free_swap(char *stock)
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
	return (stash);
}

char	*setline(char *line, char *stock)
{
	size_t	i;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (line == 0)
		return (0);
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

char	*get_next_line(int fd)
{
	int				i;
	char			*line;
	char			buffer[BUFFER_SIZE + 1];
	static char		*stock;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer[BUFFER_SIZE] = '\0';
	if (reader_buff(buffer, &i, fd, 0) == -1)
		return (0);
	if (!stock)
	{
		stock = (char *)malloc(1 * sizeof(char));
		stock[0] = '\0';
	}
	while (findstop(buffer) != 1)
	{
		reader_buff(buffer, &i, fd, BUFFER_SIZE);
		if (i == 0)
			return (gnl_eof(stock));
		stock = ft_strjoin(stock, buffer);
	}
	line = NULL;
	line = setline(line, stock);
	stock = free_swap(stock);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
		printf("%s", line);
	printf("%s", line);
}
*/