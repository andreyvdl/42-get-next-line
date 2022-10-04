/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:09:45 by adantas-          #+#    #+#             */
/*   Updated: 2022/10/03 16:09:47 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0x0);
	if (!rest)
		rest = ft_calloc(sizeof(char), 1);
	line = ft_calloc(sizeof(char), 1);
	if (rest[0] != 0)
	{
		line = cpy_1_line(rest, line);
		return (line);
	}
	line = read_fd(rest, line, fd);
	write(1, "conteudo da line: ", 18);
	write(1, line, ft_strlen(line));
	//if (rest[0] == 0)
	//	free(rest);
	if (line[0] == 0)
	{
		free(line);
		return (0x0);
	}
	return (line);
}

char	*read_fd(char *rest, char *line, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	size_t	redable;

	redable = 42;
	while (redable > 0)
	{
		redable = read(fd, buf, BUFFER_SIZE);
		if (redable < 1)
			break;
		buf[redable] = 0;
		if (ft_strchr(buf, '\n'))
		{
			line = until_newline(line, buf, rest);
			return (line);
		}
		line = ft_strjoin_mod(line, buf);
	}
	return (line);
}

char	*cpy_1_line(char *rest, char *line)
{
	size_t	i;
	size_t	j;

	free(line);
	i = 0;
	while (rest[i] != '\n' && rest[i] != 0)
		i++;
	if (rest[i] == '\n')
		line = ft_calloc(sizeof(char), i + 2);
	else if(rest[i] == 0)
		line = ft_calloc(sizeof(char), i + 1);
	j = 0;
	i = 0;
	while (rest[i] != 0 && rest[i] != '\n')
		line[j++] = rest[i++];
	line[j] = rest[i];
	rest = (char *)ft_realloc_mod(rest);
	return (line);
}

char	*until_newline(char *line, char *buf, char *rest)
{
	size_t	i;
	size_t	j;
	char	*newline;

	i = 0;
	while (buf[i] != '\n')
		i++;
	newline = ft_calloc(sizeof(char), ft_strlen(line) + i + 2);
	i = 0;
	j = 0;
	while (line[j] != 0)
		newline[i++] = line[j++];
	free(line);
	j = 0;
	while (buf[j] != '\n')
		newline[i++] = buf[j++];
	newline[i] = buf[j++];
	i = 0;
	while (buf[j] != 0)
		rest[i++] = buf[j++];
	rest[i] = 0;
	return (newline);
}
