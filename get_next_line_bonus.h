/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:23:17 by adantas-          #+#    #+#             */
/*   Updated: 2022/10/11 15:56:27 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

// get_next_line_bonus.c funcitons
char	*get_next_line(int fd);
void	cpy_1_line(char **rest, char **line);
char	*read_fd(char **rest, char **line, int fd);
char	*until_newline(char **line, char *buf, char **rest);
void	secret_trick(char **rest, char *buf, size_t n);

// get_next_line_utils_bonus.c functions
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(const char *s, int c);
void	*ft_realloc_mod(char **ptr);
char	*ft_strjoin_mod(char *s1, char *s2);

#endif
