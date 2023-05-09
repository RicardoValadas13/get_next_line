#include "get_next_line.h"

int ft_strlen(const char *s)
{
    int len;

    len = 0;
    while (s[len])
    {
        len++;
    }
    return (len);
}

int check_newline(char  *buff)
{
    while (*buff)
    {
        if (*buff == '\n')
        {
            buff++;
            return (1);
        }
        buff++;
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
    {
        free(s1);
        return (NULL);
    }
    while (s1 != NULL && s1[i])
    {
        str3[i] = s1[i];
        i++;
    }
    free(s1);
    while (s2[j])
    {
        str3[i] = s2[j];
        i++;
        j++;
        if (s2[j] == '\n')
        {
            str3[i] = s2[j];
            i++;
            break;
        }
        s2[j] = '\0';
    }
    str3[i] = '\0';
    return (str3);
}