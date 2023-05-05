#include "get_next_line.h"


int main(void)
{
  int fd;
  char *line;
  static int  i;
  
  i = 1;
  fd = open("file.txt", O_RDONLY);
  line = get_next_line(fd);

  printf("line %d: %s\n", i, line);
  i++;
}