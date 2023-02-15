/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cportuon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:53:41 by cportuon          #+#    #+#             */
/*   Updated: 2023/02/01 17:53:44 by cportuon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	char		*buff;
	static char	*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	line = ft_read_line(fd, temp, buff);
	free(buff);
	if (!line)
	{
		free(temp);
		return (0);
	}
	temp = ft_get_rest(line);
	return (line);
}

char	*ft_read_line(int fd, char *backup, char *buff)
{
	int		read_line;
	char	*aux;

	read_line = 1;
	while (read_line > 0)
	{
		read_line = read(fd, buff, BUFFER_SIZE);
		if (read_line == -1)
			return (0);
		else if (read_line == 0)
			break ;
		buff[read_line] = '\0';
		if (!backup)
			backup = ft_strdup("");
		aux = backup;
		backup = ft_strjoin(aux, buff);
		free(aux);
		aux = NULL;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (backup);
}

char	*ft_get_rest(char *line)
{
	int		i;
	char	*temp;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\0')
	{	
		return (0);
	}
	temp = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*temp == '\0')
	{
		free(temp);
		temp = NULL;
	}
	line[i + 1] = '\0';
	return (temp);
}
