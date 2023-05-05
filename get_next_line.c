#include "get_next_line.h"
#include <unistd.h>

/* int ft_strlen(char *s)
{
  int cnt;

  cnt = 0;
  while (s[cnt])
    cnt++;
  return (cnt);
}

char  *ft_strjoin(char *s1, char *s2)
{
  char  *str3;
  size_t    i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (NULL);
  str3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
  if (!str3)
    return (NULL);
  while (*s1)
  {
    str3[i] = *s1;
    i++;
    s1++;
  }
  while (*s2)
  {
    str3[i] = *s2;
    i++;
    s2++;
  }
  str3[i] = '\0';
  return (str3);
}

int ft_endline(char *buff)
{
  while (*buff)
  {
    if (*buff == '\n')
      return (0);
    buff++;    
  }
  return (1);
}

char  *get_next_line(int fd)
{
  static char *buff;
  char        *line;
  char        *temp;

  if (read(fd, buff, BUFFER_SIZE) <= 0 || fd < 0)
    return (NULL);
  temp = buff;
  while (ft_endline(buff))
  {
    read(fd, buff, BUFFER_SIZE);
    line = ft_strjoin(temp, buff);
  }
  return (line);
} */

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
        char            *d;
        const char      *s;

        d = (char *)dest;
        s = (const char *)src;
        if (!dest && !src)
                return (NULL);
        while (n--)
        {
                *d++ = *s++;
        }
        return (dest);
}


char *get_next_line(int fd) 
{
  static char buf[BUFFER_SIZE];
  static int bufpos = 0;
  static int bufsize = 0;

  char *line = NULL;
  int linelen = 0;
  int linecap = 0;

  while (1) 
  {
    if (bufpos >= bufsize) 
    {
      bufsize = read(fd, buf, BUFFER_SIZE);
      if (bufsize <= 0) 
        break;
      bufpos = 0;
    }
    char c = buf[bufpos++];
    if (c == '\n') 
      break;
    if (linelen + 1 >= linecap) 
    {
      linecap = (linecap == 0) ? 64 : linecap * 2;
      char *newline = malloc(linecap);
      if (newline == NULL) 
      {
        free(line);
        return NULL;
      }
      if (line != NULL) 
      {
        ft_memcpy(newline, line, linelen);
        free(line);
      }
        line = newline;
    }
    line[linelen++] = c;
  }

    if (line == NULL && linelen == 0) 
      return NULL;
    else
    {
      line[linelen] = '\0';
      return line;
    }
}
