#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
<<<<<<< HEAD
#include <stdlib.h>
#include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2

# endif

char  *get_next_line(int fd);
int    main(void);


=======
typedef struct s_list
{
    char    *content;
    struct s_list  *next;
}       t_list;
char  *get_next_line(int fd);
int    main(void);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100

# endif
>>>>>>> d494fda (LetsGo)
#endif