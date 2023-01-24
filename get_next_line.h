#ifndef get_next_line_h
# define get_next_line_h

# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *aux, char *buff);
static char	*read_line(int fd, char *backup, char *buff);

#endif
