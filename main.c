/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cportuon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:02:31 by cportuon          #+#    #+#             */
/*   Updated: 2023/02/21 20:02:34 by cportuon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*read;

	fd = open("tumadre", O_RDONLY);
	read = get_next_line (fd);
	printf ("First line: %s\n", read);
	free(read);
	read = get_next_line (fd);
	printf ("Second line: %s\n", read);
	free(read);
	read = get_next_line (fd);
	printf ("Third line: %s\n", read);
	free(read);
	return (0);
}
