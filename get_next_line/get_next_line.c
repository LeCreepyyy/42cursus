/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoirot <vpoirot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:51:04 by vpoirot           #+#    #+#             */
/*   Updated: 2023/03/07 14:14:28 by vpoirot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	reader_buff(char *buffer, int *i, int fd, int size)
{
	*i = read(fd, buffer, size);
	if (*i <= 0)
	{
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
			return (0);
		i++;
	}
	return (1);
}

char	*free_swap(size_t i, char *stock)
{
	int		j;
	int		t;
	char	*stash;

	t = 1;
	i = -1;
	while (stock[++i])
		t++;
	stash = malloc((t) * sizeof(char));
	if (!stash)
		return (0);
	i -= t;
	j = -1;
	while (stock[++i])
	{
		++j;
		stash[j] = stock[i];
	}
	stash[++j] = '\0';
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
	reader_buff(buffer, &i, fd, 0);
	if (!stock)
	{
		stock = (char *)malloc(1 * sizeof(char));
		stock[0] = '\0';
	}
	reader_buff(buffer, &i, fd, BUFFER_SIZE);
	stock = ft_strjoin(stock, buffer);
	if (i <= 0)
		return (0);
	while (1)
	{
		reader_buff(buffer, &i, fd, BUFFER_SIZE);
		if (i <= 0)
			break ;
		stock = ft_strjoin(stock, buffer);
		if (findstop(buffer) == 0)
			break ;
	}
	line = NULL;
	line = setline(line, stock);
	stock = free_swap(size_count(stock), stock);
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
