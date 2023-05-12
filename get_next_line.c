#include "get_next_line.h"


char    *get_next_line(int fd)
{
    static char     buff[BUFFER_SIZE + 1];
    char           *line;
    static int      i;
    int             j = 0;
    line = NULL;
    if(fd <= 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
        return(NULL);
    while( *buff || (read(fd, buff, BUFFER_SIZE)) > 0) 
    {
        printf("buff_iter = %s | i = %d\n", &buff[i], i);
        printf("buffer = %s\n", buff);
        line = thats_line(line, &buff[i]);
        i = 0;
        i = check_newline(&buff[i]);
        if (i > 0)
        {
            if (buff[BUFFER_SIZE] == '\n')
                i = 0;
            printf("i = %d\n", i);
            while (j++ < BUFFER_SIZE)
                printf("clean_buffer = %c\n", buff[j]);
            break; 
        }
    }
    return (line);
}

int	main(void)
{
    int     fd;
    char    *line;
    int      i;

    fd = open("file.txt", O_RDONLY);

 /*    line = get_next_line(fd);
    printf("%s", line); */
    i = 1;
    while (1)
    {
        line = get_next_line(fd);
        printf("Line %d:%s", i, line);
        if (line == NULL)
        {
            printf("\n");
            break ;
        }
        i++;
        free(line);
    } 
    return (0);
}

