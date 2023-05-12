#include "get_next_line.h"

int ft_strlen(const char *s)
{
    int len;

    len = 0;
    while (s[len] && s[len] != '\n')
    {
        len++;
    }
    return (len);
}

int check_newline(char  *buff)
{
    int     i;

    i = 0;
/*  printf("buff_check = %s\n", buff);*/
    while (buff[i])
    {
        if (buff[i] == '\n')
        {
            buff[i] = '\0';
            i++;
            /* printf("buff: %c\n", buff[0]); */
           /*printf("valor: %c\n", buff[i]); */
            return (i);
        }
        buff[i] = '\0';
        i++;
    }
    return (0);
}

char    *thats_line(char  *s1, char  *s2)
{
    char    *str3;
    size_t  i;
    size_t  j;
    size_t  len_s1;

    i = 0;
    j = 0;
    len_s1 = 0;
    if (s1 != NULL)
        len_s1 = ft_strlen(s1);
    str3 = (char *)malloc(len_s1 + ft_strlen(s2) + 1);
    if (!str3)
        return (NULL);
    while (s1 != NULL && s1[i])
    {
        str3[i] = s1[i];
        i++;
    }
    if (s1)
        free(s1);
    while (*s2)
    {
        str3[i] = *s2;
        i++;
        if (*s2 == '\n')
            break;
        s2++;
    }
    str3[i] = '\0';
    return (str3);
}