#include "get_next_line.h"

char	*ft_get_rest(char *line)
{
	int		i;
	char	*temp;

	i = 0;
	if(!line)
		return(0);
	while(line[i])
	{
		if(line[i] == '\n')
		{
			temp = ft_substr(line, i + 1, ft_strlen(len) - i);
			return(0);
		}
		i++;
	}
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
	line = ft_read_line(fd, temp, buff);
	free(buff);
	if(!line)
	{
		free(temp);
		return(0);
	}
	temp = ft_get_rest(line);
	return(line);
}
