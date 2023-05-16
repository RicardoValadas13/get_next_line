#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000

# endif

char	*get_next_line(int fd);
int		ft_strlen(const char *s);
int		check_newline(char *buff);
char	*thats_line(char *s1, char *s2);
void	*ft_bzero(void *s, size_t n);

#endif