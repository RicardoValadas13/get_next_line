#include "get_next_line.h"

int ft_strlen(const char *s)
{
    int len = 0;
    while (s[len])
    {
        len++;
    }
    return len;
}

int check_newline(char *buff)
{
    while (*buff)
    {
        if (*buff == '\n')
        {
            buff++;
            return 1;
        }
        buff++;
    }
    return 0;
}

char *thats_line(char *s1, char *s2)
{
    char *str3;
    size_t i = 0;
    size_t j = 0;
    size_t len_s1 = 0;

    if (s1 != NULL)
        len_s1 = ft_strlen(s1);

    str3 = (char *)malloc(len_s1 + ft_strlen(s2) + 1);
    if (!str3)
    {
        free(s1); // Free previously allocated s1 if memory allocation fails
        return NULL;
    }

    while (s1 != NULL && s1[i])
    {
        str3[i] = s1[i];
        i++;
    }
    free(s1); // Free previously allocated s1

    while (s2[j])
    {
        str3[i] = s2[j];
        s2[j] = '\0';
        i++;
        j++;
        if (*s2 == '\n')
        {
            str3[i] = s2[j];
            i++;
            break;
        }
    }
    str3[i] = '\0';
    return str3;
}

char *get_next_line(int fd)
{
    static char buff[BUFFER_SIZE + 1];
    char *line = NULL;

    if (fd <= 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
        return NULL;

    while (*buff || (read(fd, buff, BUFFER_SIZE)) > 0)
    {
        char *new_line = thats_line(line, buff);
        if (!new_line)
        {
            free(line); // Free previously allocated line if memory allocation fails
            return NULL;
        }
        line = new_line;

        if (check_newline(buff))
            break;
    }
    return line;
}
int	main(void)
{
    int     fd;
    char    *line;

    fd = open("file.txt", O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        printf("%s", line);
        if (line == NULL)
            break ;
        free(line);
    }
    return (0);
}
