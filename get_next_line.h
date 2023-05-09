#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2

# endif


char  *get_next_line(int fd);
int ft_strlen(const char *s);
int check_newline(char  *buff);
char    *thats_line(char  *s1, char  *s2);

#endif