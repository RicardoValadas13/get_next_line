#include "get_next_line.h" 


int main()
{
    int fd;
    char    *line;

    fd = open("file.txt", O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        printf("%s", line);
        free(line);
    }
    return (0);
}

char *get_next_line(int fd)
{
    static t_list   *stash = NULL;
    char            *line;
    int             readed;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
        return (NULL);
    readed = 1;
    line = NULL;
    read_and_stash(fd, &stash, &readed);
    if(!stash)
        return (NULL);
    return(line);
}

void    read_and_stash(int fd, t_list **stash, int *readed_ptr)
{
    char    *buff;

    buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (buff = NULL)
        return (NULL);
    while (!found_new_linw(*stash) && readed_ptr != 0)
    {
        *readed_ptr = read(fd, buff, BUFFER_SIZE);
        if((*stash == NULL && *readed_ptr == 0) || *readed_ptr == -1)
        {
            free(buff);
            return ;
        }
        buff[*readed_ptr] = '\0';
    }
}