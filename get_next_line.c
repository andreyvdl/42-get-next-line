/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:09:45 by adantas-          #+#    #+#             */
/*   Updated: 2022/10/14 10:54:29 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (0x0);
	if (!rest)
		rest = ft_calloc(sizeof(char), 1);
	line = ft_calloc(sizeof(char), 1);
	if (rest && rest[0] != 0)
	{
		cpy_1_line(&rest, &line);
		if (!ft_strchr(line, '\n'))
			line = read_fd(&rest, &line, fd);
		return (line);
	}
	line = read_fd(&rest, &line, fd);
	if (line[0] == 0 && rest[0] == 0)
	{
		free(line);
		line = 0x0;
		free(rest);
		rest = 0x0;
		return (0x0);
	}
	return (line);
}

void	cpy_1_line(char **rest, char **line)
{
	size_t	i;
	size_t	j;

	i = 0;
	while ((*rest)[i] != '\n' && (*rest)[i] != 0)
		i++;
	free(*line);
	if ((*rest)[i] == '\n')
		*line = ft_calloc(sizeof(char), i + 2);
	else if ((*rest)[i] == 0)
		*line = ft_calloc(sizeof(char), i + 1);
	j = i;
	while (i != 0)
		(*line)[j--] = (*rest)[i--];
	(*line)[j] = (*rest)[i];
	*rest = (char *)ft_realloc_mod(rest);
}

char	*read_fd(char **rest, char **line, int fd)
{
	char	*buf;
	size_t	readable;

	readable = 42;
	buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	while (readable > 0)
	{
		readable = read(fd, buf, BUFFER_SIZE);
		buf[readable] = '\0';
		if (readable == 0)
			break ;
		if (ft_strchr(buf, '\n'))
		{
			*line = until_newline(line, buf, rest);
			free(buf);
			buf = 0x0;
			return (*line);
		}
		*line = ft_strjoin_mod(*line, buf);
	}
	free(buf);
	buf = 0x0;
	return (*line);
}

char	*until_newline(char **line, char *buf, char **rest)
{
	size_t	i;
	size_t	j;
	char	*newline;

	i = 0;
	while (buf[i] != '\n')
		i++;
	newline = ft_calloc(sizeof(char), ft_strlen(*line) + i + 2);
	i = 0;
	j = 0;
	while ((*line)[j] != 0)
		newline[i++] = (*line)[j++];
	free(*line);
	j = 0;
	while (buf[j] != '\n')
		newline[i++] = buf[j++];
	newline[i] = buf[j++];
	free(*rest);
	*rest = 0x0;
	if (buf[j] != 0)
		secret_trick(rest, buf, j);
	return (newline);
}

void	secret_trick(char **rest, char *buf, size_t n)
{
	size_t	i;

	i = 0;
	*rest = ft_calloc(sizeof(char), ft_strlen(buf) - n + 1);
	while (buf[n] != 0)
		(*rest)[i++] = buf[n++];
}
