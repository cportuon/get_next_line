/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cportuon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:26:51 by cportuon          #+#    #+#             */
/*   Updated: 2022/11/08 12:26:53 by cportuon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    int     i;
    int     j;
    char    *buff;
    size_t  read_line;
    char    *line;
    
    i = 0;
    j = 0;
    buff = malloc(sizeof(char) * BUFFER_SIZE + 100);
    line = malloc(sizeof(char) * BUFFER_SIZE + 100);
    read_line = read(fd, buff, BUFFER_SIZE);
    buff[read_line] = '\0';
    if (fd <= 0 || BUFFER_SIZE == 0)
        return (NULL);
    if (read_line == 0)
        return(NULL);
    while(buff[i] && buff[i] != '\n')
    {
        line[j] = buff[i];
        j++;
        i++;
        if (!buff[i])
        {
            i = 0;
            read_line = read(fd, buff, BUFFER_SIZE);
            buff[read_line] = '\0';
        }
    }
    line[j] = '\0'; 
    return (line);
}

int main(void)
{
    char    *lectura;
    int     fd;

    fd = open("read.txt", O_RDONLY);
    lectura = get_next_line(fd);
    lectura = get_next_line(fd);
    printf("%s", lectura);
    close (fd);
    return (0);
}
