#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
  int f_d;
  int bytes;
  char *buf;
  size_t BUFFER_SIZE;
  BUFFER_SIZE = 42;

  f_d = open("file.txt", O_RDONLY);
  printf("File descriptor: %d\n", f_d);

  bytes = read(f_d, buf, BUFFER_SIZE);
  printf("Bytes read: %d\n", bytes);
}