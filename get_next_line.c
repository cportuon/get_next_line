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
    int         i;                                  // Contador de buff
    int         j;                                  // Contador de line
    static char *buff;                              // Guardamos lo que BUFFER_SIZE le pide
    size_t      read_line;                          // Guardamos el resultado del read 
    char        *line;                              // Guardamos la linea para mostrarla después
    
    i = 0;
    j = 0;
    line = malloc(sizeof(char) * BUFFER_SIZE + 100);  // Damos tamaño a line
    if (fd <= 0 || BUFFER_SIZE == 0)                // Comprobaciones iniciales
        return (NULL);
    if (!buff)                                      // Solo la 1ª vez le damos el tamaño a buff
    {
        buff = malloc(sizeof(char) * BUFFER_SIZE);  
        buff[0] = '\0';                                    // Para evitar errores ponemos (null)
    }
    while (buff[i] && buff[i] != '\n')
        i++;
    while (buff[i])
    {
        line[j] = buff[i];
        j++;
        i++;
    }
    i = 0;
    read_line = read(fd, buff, BUFFER_SIZE);            // Guardamos el número de bits de BUFFER_SIZE del archivo fd en buff 
    buff[read_line] = '\0';                             // Al final de buff le ponemos (null)
    while(buff[i] && buff[i] != '\n')                   // Si buff existe y no es salto de línea
    {
        line[j] = buff[i];                              // Vamos solapando todos los buff en line
        j++;
        i++;
        if (buff[i] == '\0')                            // Al final del buff siempre tenemos un (null), por lo tanto tenemos que resetear buff
        {
            i = 0;                                      // Reseteamos i para leer el buff desde el principio la siguiente vez
            read_line = read(fd, buff, BUFFER_SIZE);    // Guardamos los siguientes bits que indica BUFFER_SIZE en buff
            buff[read_line] = '\0';                     // Indicamos el final del string
        }
    }
    line[j] = '\0';                                     // Indicamos el final del string
    return (line);
}

int main(void)
{
    char    *lectura;
    int     fd;

    fd = open("read.txt", O_RDONLY);    // Guardo el archivo completo
    lectura = get_next_line(fd);        // Le paso el archivo de texto a la función y lo guardo
    printf("Primera línea: %s", lectura);              // Printeo el resultado de la función
    lectura = get_next_line(fd);
    printf("Segunda línea: %s", lectura);
    lectura = get_next_line(fd);
    printf("Tercera línea: %s", lectura);
    close (fd);
    return (0);
}
