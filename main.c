#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*read;

	fd = open("read.txt", O_RDONLY);
	read = 	get_next_line(fd);
	printf("First line: %s\n", read);
	free(read);
	read = 	get_next_line(fd);
	printf("Second line: %s\n", read);
	free(read);
	read = 	get_next_line(fd);
	printf("Third line: %s\n", read);	
	free(read);
	return(0);
}
