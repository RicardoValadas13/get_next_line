#include "get_next_line.h"

int ft_strlen(const char *s)
{
    int len = 0;
    while (s[len] && s[len] != '\n')
    {
        len++;
    }
    return len;
}

int check_newline(char *buff)
{
    int i = 0;
    while (buff[i])
    {
        if (buff[i] == '\n')
        {
            buff[i] = '\0';
            return (i + 1);
        }
        i++;
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
        return NULL;
    while (s1 != NULL && s1[i])
    {
        str3[i] = s1[i];
        i++;
    }
    if (s1)
        free(s1);
    while (s2[j])
    {
        str3[i + j] = s2[j];
        if (s2[j] == '\n')
        {
            str3[i + j + 1] = '\0';
            return str3;
        }
        j++;
    }
    str3[i + j] = '\0';
    return str3;
}

char *get_next_line(int fd)
{
    static char buff[BUFFER_SIZE + 1];
    char *line = NULL;
    static int i = 0;
    int read_bytes = 0;
    int newline_index = 0;

    if (fd <= 0 || read(fd, buff, 0) < 0 || BUFFER_SIZE <= 0)
        return NULL;

    while (1)
    {
        if (i == 0)
        {
            read_bytes = read(fd, buff, BUFFER_SIZE);
            if (read_bytes <= 0)
            {
                if (line != NULL && line[0] != '\0')
                    return line;
                else
                    return NULL;
            }
            buff[read_bytes] = '\0';
        }

        line = thats_line(line, &buff[i]);
        newline_index = check_newline(&buff[i]);

        if (newline_index > 0)
        {
            i += newline_index;
            return line;
        }
        else if (read_bytes == 0)
        {
            if (line != NULL && line[0] != '\0')
                return line;
            else
                return NULL;
        }
        i = 0;
    }
}

int main(void)
{
    int fd;
    char *line;
    int i;

    fd = open("file.txt", O_RDONLY);

    i = 1;
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
        {
            break;
        }
        printf("Line %d: %s\n", i, line);
        i++;
        free(line);
    }
    return 0;
}
