#include "get_next_line.h"
#include <unistd.h>

char  *get_next_line(int fd)
{
  char *buf;
  size_t BUFFER_SIZE;
  BUFFER_SIZE = 42;
  read(fd, buf, BUFFER_SIZE);
}
