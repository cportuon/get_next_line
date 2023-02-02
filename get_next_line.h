/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cportuon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:54:16 by cportuon          #+#    #+#             */
/*   Updated: 2023/02/01 17:54:17 by cportuon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef get_next_line_h
# define get_next_line_h

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	    *get_next_line(int fd);
char	    *ft_strjoin(char *aux, char *buff);
int         ft_strlen(char *str);
char        *ft_strdup(char *s);
char        *ft_substr(char *line, int	start, int strlen2);
char        *ft_strchr(const char *str, int c);
char	    *ft_read_line(int fd, char *backup, char *buff);
char	    *ft_get_rest(char *line);

# ifndef BUFFER_SIZE
#   define BUFFER_SIZE 100
# endif

#endif
