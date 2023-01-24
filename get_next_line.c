#include "get_next_line.h"

char	*ft_get_rest(char *line)
{
	
}

static char	*ft_read_line(int fd, char *backup, char *buff)
{
	int	read_line;
	char	*aux;

	read_line = 1;
	while(read_line > 0)
	{
		read_line = read(fd, buff, BUFFER_SIZE);
		if(read_line < 0)
			return(0);
		else if(read_line == 0)
			break ;
		if(!backup)
		{
			backup = (char *)malloc(sizeof(char) * 1);
			backup[0] = '\0';
		}
		buff[read_line] = '\0';
		aux = backup;
		backup = ft_strjoin(aux, buff);
		
	}
	return(backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buff;
	static char	*temp;
	
	if(fd < 0 || BUFFER_SIZE <= 0)
		return(0);
	buff = (char *)malloc(sizeof(char *) * BUFFER_SIZE + 1);
	if(!buff)
		return(0);
	line = ft_read_line(fd, backup, buff);
	free(buff);
	if(!line)
	{
		free(backup);
		return(0);
	}
	backup = ft_get_rest(line);
	return(line);
}
