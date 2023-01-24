#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char	*read;

	fd = open("read.txt", O_RDONLY);
	read = 	get_next_line(fd);
	printf("First line: %s\n", read);	
	return(0);
}
