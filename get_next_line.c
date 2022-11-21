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
    char    *buff;
    size_t  read_line;

    i = 0;
    buff = malloc(sizeof(char) * BUFFER_SIZE);
    read_line = read(fd, buff, BUFFER_SIZE);
    if (fd <= 0)
        return (NULL);
    if (!buff)
        return (NULL);
    while(buff[i])
    {
        if (buff[i] == '\n')
            return (0);
        write(1, &buff[i], 1);
        i++;
    }
    return (0);
}

int main(void)
{
    int     fd;
    char    *buff;

    fd = open("read.txt", O_RDONLY);
    buff = malloc(sizeof(char) * BUFFER_SIZE);
    //printf("%zd", read(fd, buff, BUFFER_SIZE));
    //printf("%s", buff);
    get_next_line(fd);
    close(fd);
    return (0);
}
