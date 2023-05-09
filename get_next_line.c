#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char     buff[BUFFER_SIZE + 1];
    char           *line;
    char           *new_line;

    line = NULL;
    if(fd <= 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
        return(NULL);
    while(*buff || (read(fd, buff, BUFFER_SIZE)) > 0) 
    {
        new_line = thats_line(line, buff);
        if (!new_line)
        {
            free(line);
            return NULL;
        }
        line = new_line;
        if (check_newline(buff))
            break; 
    }
    return (line);
}

int	main(void)
{
    int     fd;
    char    *line;

    fd = open("file.txt", O_RDONLY);

    line = get_next_line(fd);
    printf("%s", line);
    /* while (1)
    {
        line = get_next_line(fd);
        printf("%s", line);
        if (line == NULL)
            break ;
        free(line);
    } */
    return (0);
}

