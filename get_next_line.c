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

char    *get_next_line(int fd);

int main(void)
{
    int     fd;
    char    *buff;

    fd = open("read.txt", O_RDONLY);
    printf("main_fd: %i\n", fd);//----------------variable fd
    buff = malloc(sizeof(char) * BUFFER_SIZE);
    printf("main_buff: %s\n", buff);//----------------variable buff
    get_next_line(fd);
    close(fd);
    return (0);
}

char    *get_next_line(int fd)
{
    printf("gnl_fd: %i\n", fd);//----------------variable  fd
    int     i;
    char    *buff;
    size_t  read_line;
    
    i = 0;
    buff = malloc(sizeof(char) * BUFFER_SIZE);
    printf("gnl_buff_1: %s\n", buff);//----------------variable buff
    read_line = read(fd, buff, BUFFER_SIZE);
    printf("gnl_read_line: %zu\n", read_line);//----------------variable read_line
    printf("gnl_BUFFER_SIZE: %d\n", BUFFER_SIZE);//----------------variable BUFFER_SIZE
    if (fd <= 0)
        return (NULL);
    if (!buff)
        return (NULL);
    while(buff[i] && buff[i] != '\n')
    {
        if (buff[i] == '\n')
        {
            write(1, "\n", 1);
            printf("gnl_buff_2: %s\n", buff);//----------------variable buff
            return (0);
        }
        write(1, &buff[i], 1);
        i++;
    }
    return (0);
}
